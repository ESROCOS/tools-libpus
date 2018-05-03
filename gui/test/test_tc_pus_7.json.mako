{ "activities": [
  {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [1, 5, 12, 20], "msg": 0}
  },
  {
    "interval": 1,
    "comment": "Enable param monitoring function",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(12, 15)},
          ${macros.acks(0,0,0,1)},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {}
        }
      }
    }
  },
  {
    "interval": 1,
    "comment": "Sets HK_PARAM_BOOL01 report",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(12, 1)},
          ${macros.acks(0,0,0,1)},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "pmon_id": ${HK_PARAM_BOOL01}
          }
        }
      }
    }
  },
  {
    "interval": 1,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "param_id": ${SET_HK_OUT_OF_RANGE_PARAM},
            "value": 1
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
    "interval": 15,
    "comment": "Disables parameter monitoring report",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(12, 16)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {}
        }
      }
    }
  },
  {
    "interval": 1,
    "action": "savedb",
    "params": "dump_test_07.db"
  }
]}