{ "activities": [
  {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [5, 20], "msg": 0}
  },
  {
    "interval": 2,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "param_id": ${SET_THROW_EVENTS_PARAM},
            "value": true
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          "src_id": 1,
          ${macros.acks()},
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 10,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "param_id": ${SET_THROW_EVENTS_PARAM},
            "value": false
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          "src_id": 1,
          ${macros.acks()},
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 1,
    "action": "savedb",
    "params": "dump_test_st03.db"
  }
]}