{ "activities": [
   {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [8], "msg": 0}
  },
  {
    "interval": 0,
    "comment": "Runs function 0",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
      "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "function_id": 0
          }
        }
      }
    }
  },
  {
    "interval": 1,
    "comment": "Runs function 1",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
      "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "function_id": 1
          }
        }
      }
    }
  },
  {
    "interval": 0,
    "comment": "Runs function 2",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
      "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "function_id": 2
          }
        }
      }
    }
  },
  {
    "interval": 1,
    "comment": "Runs invalid function",
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
      "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        },
        "user_data": {
          "src_data": {
            "function_id": 3
          }
        }
      }
    }
  },
  {
    "interval": 1,
    "action": "savedb",
    "params": "dump_test_st04.db"
  }
]}