{ "activities": [
  {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [11, 17], "msg": [1,4, 2]}
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
          ${macros.tc_type(11, 1)},
          "src_id": 1,
          ${macros.acks()},
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 2,
    "comment": "Insert activities",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(11, 4)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "activity1": {
              "time": ${macros.datetime_to_int("20/08/2018 09:46:00")},
              "packet": {
                ${macros.primary_header_defaults()},
                "data": {
                  "pck_sec_head": {
                    ${macros.tc_type(17, 1)},
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
            "activity2": {
              "time": ${macros.datetime_to_int("20/08/2018 09:46:05")},
              "packet": {
                ${macros.primary_header_defaults()},
                "data": {
                  "pck_sec_head": {
                    ${macros.tc_type(17, 1)},
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
            "activity3": {
              "time": ${macros.datetime_to_int("20/08/2018 09:46:10")},
              "packet": {
                ${macros.primary_header_defaults()},
                "data": {
                  "pck_sec_head": {
                    ${macros.tc_type(17, 1)},
                    ${macros.acks()},
                    "src_id": 1,
                    "tc_packet_pus_version_number": 2
                  },
                  "user_data": {
                    "src_data": {}
                  }
                }
              }
            }
          }
        }
      }
    }
  },
  {
    "interval": 1,
    "action": "savedb",
    "params": "dump_test_06.db"
  }
]}