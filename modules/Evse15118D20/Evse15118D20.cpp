// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#include "Evse15118D20.hpp"

namespace module {

void Evse15118D20::init() {
    invoke_init(*p_charger);
    invoke_init(*p_extensions);
}

void Evse15118D20::ready() {
    invoke_ready(*p_charger);
    invoke_ready(*p_extensions);
}

} // namespace module
