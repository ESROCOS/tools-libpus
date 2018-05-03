{ "activities": [
  {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [9], "msg": [1,2]}
  },
  {
    "interval": 0,
    "comment": "Changes rate report to 1 every telemetry",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(9, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "exp_rate": 0
          }
        }
      }
    }
  },
  {
    "interval": 8,
    "comment": "Changes rate report to 2 every telemetry",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(9, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "exp_rate": 1
          }
        }
      }
    }
  },
  {
    "interval": 10,
    "action": "savedb",
    "params": "dump_test_st05.db"
  }
]}