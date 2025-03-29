// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2022 Pionix GmbH and Contributors to EVerest

const { boot_module } = require('everestjs');
const { setInterval } = require('timers');

let state_ev;
let state_evse;
let cntmatching;

let use_pipes = false;

const STATE_UNKNOWN   = 0;
const STATE_UNMATCHED = 1;
const STATE_MATCHING  = 2;
const STATE_MATCHED   = 3;

function state_to_string(s) {
  switch (s) {
    case STATE_UNMATCHED:
      return 'UNMATCHED';
    case STATE_MATCHING:
      return 'MATCHING';
    case STATE_MATCHED:
      return 'MATCHED';
    default:
      return '';
  }
}

function state_from_string(s) {
  switch (s) {
    case 'UNMATCHED':
      return STATE_UNMATCHED;
    case 'MATCHING':
      return STATE_MATCHING;
    case 'MATCHED':
      return STATE_MATCHED;
    default:
      return STATE_UNKNOWN;
  }
}

function set_unmatched_ev(mod) {
  if (state_ev !== STATE_UNMATCHED) {
    state_ev = STATE_UNMATCHED;

    mod.provides.ev.publish.state(state_to_string(state_ev));
    mod.provides.ev.publish.dlink_ready(false);
  }
}

function set_matching_ev(mod) {
  state_ev    = STATE_MATCHING;
  cntmatching = 0;

  mod.provides.ev.publish.state(state_to_string(state_ev));
}

function set_matched_ev(mod) {
  state_ev = STATE_MATCHED;

  mod.provides.ev.publish.state(state_to_string(state_ev));
  mod.provides.ev.publish.dlink_ready(true);
}

function simulation_loop(mod) {
  // if both are in matching for 2 seconds SLAC matches
  cntmatching += 1;

  if (state_ev === STATE_MATCHING && state_evse === STATE_MATCHING && cntmatching > 2 * 4) {
    set_matched_ev(mod);
  }

  publish_oob(mod);
}

function publish_oob(mod) {
  let data = {
    source: 'slac/ev',
    state:  state_to_string(state_ev),
  };

  if (use_pipes) {
    process.stdout.write(`${JSON.stringify(data)}\n`);
  } else {
    mod.mqtt.publish('everest_external/oob/slac/ev', JSON.stringify(data));
  }
}

function process_oob(mod, data) {
  if (data.source === 'slac/evse') {
    state_ev = state_from_string(data.state);
  }
}

function subscribe_oob(mod) {
  if (use_pipes) {
    process.stdin.on('data', (chunk) => {
      let lines = chunk.toString().trim().split('\n');

      for (let i = 0; i < lines.length; i++) {
        try {
          process_oob(mod, JSON.parse(lines[i]));
        } catch {
          continue;
        }
      }
    });
  } else {
    mod.mqtt.subscribe('everest_external/oob/slac/evse', (_, chunk) => {
      process_oob(mod, JSON.parse(chunk));
    });
  }
}

async function boot({setup, config}) {
  state_ev    = STATE_UNMATCHED;
  state_evse  = STATE_UNMATCHED;
  cntmatching = 0;

  use_pipes = config.module.use_pipes;

  setup.provides.ev.register.reset((mod) => {
    set_unmatched_ev(mod);
  });

  setup.provides.ev.register.trigger_matching((mod) => {
    set_matching_ev(mod);
    return true;
  });
}

async function run(mod) {
  mod.provides.ev.publish.state(state_to_string(state_ev));

  subscribe_oob(mod);
  setInterval(simulation_loop, 250, mod);
}

boot_module(boot).then(run);