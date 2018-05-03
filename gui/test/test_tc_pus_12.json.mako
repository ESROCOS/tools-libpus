{ "activities": [
  {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [1, 5, 17, 19, 20], "msg": [1, 2, 3, 4, 5, 6, 7, 8]}
  },
  {
    "interval": 0,
    "comment": "",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(19, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "request": {
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
            },
            "event_id": ${EVENT_INFO_01}
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
        "pck_sec_head": {
          ${macros.tc_type(19, 4)},
          ${macros.acks()},
          "tc_packet_pus_version_number": 2,
          "src_id": 1
        },
        "user_data": {
          "src_data": {
            "event_id": ${EVENT_INFO_01}
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
            "param_id": ${SET_THROW_ONE_EVENT_PARAM},
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
        "pck_sec_head": {
          ${macros.tc_type(19, 5)},
          ${macros.acks()},
          "tc_packet_pus_version_number": 2,
          "src_id": 1
        },
        "user_data": {
          "src_data": {
            "event_id": ${EVENT_INFO_01}
          }
        }
      }
    }
  },
  {
    "interval": 10,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(19, 4)},
          ${macros.acks()},
          "tc_packet_pus_version_number": 2,
          "src_id": 1
        },
        "user_data": {
          "src_data": {
            "event_id": ${EVENT_INFO_01}
          }
        }
      }
    }
  },
  {
    "interval": 10,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "pck_sec_head": {
          ${macros.tc_type(19, 2)},
          ${macros.acks()},
          "tc_packet_pus_version_number": 2,
          "src_id": 1
        },
        "user_data": {
          "src_data": {
            "event_id": ${EVENT_INFO_01}
          }
        }
      }
    }
  },
  {
    "interval": 1,
    "action": "savedb",
    "params": "dump_test_st12.db"
  }
]}
