// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#include "ev_slacImpl.hpp"

namespace module {
namespace ev_slac {

void ev_slacImpl::init() {
}

void ev_slacImpl::ready() {
}

void ev_slacImpl::handle_reset() {
    // your code for cmd reset goes here
}

bool ev_slacImpl::handle_trigger_matching() {
    // your code for cmd trigger_matching goes here
    return true;
}

} // namespace ev_slac
} // namespace module
