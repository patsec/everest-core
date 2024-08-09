// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#include "EvSlacSimulator.hpp"

namespace module {

void EvSlacSimulator::init() {
    invoke_init(*p_ev_slac);
}

void EvSlacSimulator::ready() {
    invoke_ready(*p_ev_slac);
}

} // namespace module
