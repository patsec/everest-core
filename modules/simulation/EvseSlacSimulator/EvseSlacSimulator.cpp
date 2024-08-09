// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#include "EvseSlacSimulator.hpp"

namespace module {

void EvseSlacSimulator::init() {
    invoke_init(*p_evse_slac);
}

void EvseSlacSimulator::ready() {
    invoke_ready(*p_evse_slac);
}

} // namespace module
