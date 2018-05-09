{ "activities": [
  {
    "interval": 0,
    "comment": "Changes rate report to 1 every telemetry",
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
              "time": ${macros.datetime_to_int("12/04/2018 13:40:00")},
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
              "time": ${macros.datetime_to_int("12/04/2018 13:40:02")},
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
              "time": ${macros.datetime_to_int("12/04/2018 13:40:04")},
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
  }
]}