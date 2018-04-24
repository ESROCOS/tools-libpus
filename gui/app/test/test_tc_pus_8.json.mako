{ "activities": [
  {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [17], "msg": 0}
  },
  {
    "interval": 0,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {}
        },
        "pck_sec_head": {
          ${macros.tc_type(17, 1)},
          "src_id": 1,
          ${macros.acks()},
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 3,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {}
        },
        "pck_sec_head": {
          ${macros.tc_type(17, 1)},
          ${macros.acks()},
          "tc_packet_pus_version_number": 2,
          "src_id": 1
        }
      }
    }
  },
  {
    "interval": 1,
    "action": "savedb",
    "params": "dump_test_st17.db"
  }
]}