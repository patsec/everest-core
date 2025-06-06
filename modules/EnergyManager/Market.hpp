// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#ifndef MARKET_HPP
#define MARKET_HPP

// headers for required interface implementations
#include <generated/interfaces/energy/Interface.hpp>
#include <utils/date.hpp>
#include <vector>

using namespace std::chrono_literals;

namespace module {

typedef std::vector<types::energy::ScheduleReqEntry> ScheduleReq;
typedef std::vector<types::energy::ScheduleResEntry> ScheduleRes;
typedef std::vector<types::energy::ScheduleSetpointEntry> ScheduleSetpoints;

class globals_t {
public:
    void init(date::utc_clock::time_point _start_time, int _interval_duration, int _schedule_duration,
              float _slice_ampere, float _slice_watt, bool _debug,
              const types::energy::EnergyFlowRequest& energy_flow_request);
    date::utc_clock::time_point start_time; // common start point
    std::chrono::minutes interval_duration; // interval duration
    int schedule_length;                    // total forcast length (in counts of (non-regular) intervals)
    float slice_ampere;                     // ampere_slices for trades
    float slice_watt;                       // ampere_slices for trades
    bool debug{false};
    ScheduleReq zero_schedule_req, empty_schedule_req;
    ScheduleRes zero_schedule_res, empty_schedule_res;
    ScheduleSetpoints empty_schedule_setpoints;

private:
    void create_timestamps(const types::energy::EnergyFlowRequest& energy_flow_request);
    void add_timestamps(const types::energy::EnergyFlowRequest& energy_flow_request);
    template <typename T> void create_empty_schedule(T& s);
    std::vector<date::utc_clock::time_point> timestamps;
};

extern globals_t globals;

class time_probe {
public:
    void start();
    void pause();
    int stop();

private:
    std::chrono::high_resolution_clock::time_point timepoint_start;
    std::chrono::nanoseconds total_duration{0};
    bool running{false};
};

class Market {
public:
    Market(types::energy::EnergyFlowRequest& _energy_flow_request, const float __nominal_ac_voltage,
           Market* __parent = nullptr);

    void trade(const ScheduleRes& s);

    bool is_root();

    void get_list_of_evses(std::vector<Market*>& list);
    std::vector<Market*> get_list_of_evses();
    ScheduleReq get_available_energy_import();
    ScheduleReq get_available_energy_export();
    ScheduleSetpoints get_setpoints() {
        return setpoints;
    };

    ScheduleRes get_sold_energy();

    Market* parent();

    float nominal_ac_voltage();

    // local request only for this node
    types::energy::EnergyFlowRequest& energy_flow_request;

private:
    Market* _parent;
    std::list<Market> _children;
    float _nominal_ac_voltage;

    // main data structures
    ScheduleReq import_max_available, export_max_available;
    ScheduleSetpoints setpoints;
    ScheduleRes sold_root;
    std::vector<ScheduleRes> sold_leaves;

    ScheduleReq get_max_available_energy(const ScheduleReq& request);
    ScheduleReq get_available_energy(const ScheduleReq& available, bool add_sold);
    ScheduleSetpoints resample(const ScheduleSetpoints& request);
};

float get_watt_from_freq_table(const std::vector<types::energy::FrequencyWattPoint>& table, float freq);
void apply_limit_if_smaller(std::optional<types::energy::NumberWithSource>& base, float limit,
                            const std::string& source);
void apply_setpoints(ScheduleReq& imp, ScheduleReq& exp, const ScheduleSetpoints& setpoints, std::optional<float> freq);

} // namespace module

#endif // MARKET_HPP
