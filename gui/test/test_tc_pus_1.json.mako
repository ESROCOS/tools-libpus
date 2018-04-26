{ "activities": [
  {
    "interval": 0,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "function_id": 0
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks(start=1)},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 3,
    "packet": {
      ${macros.primary_header_defaults(1)},
      "data": {
        "user_data": {
          "src_data": {
            "function_id": 0
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks(completion=1)},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 3,
    "packet": {
      ${macros.primary_header_defaults(2)},
      "data": {
        "user_data": {
          "src_data": {
            "function_id": 0
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks(progress=1)},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 3,
    "packet": {
      ${macros.primary_header_defaults(3)},
      "data": {
        "user_data": {
          "src_data": {
            "function_id": 0
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks(acceptance=1)},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 3,
    "packet": {
      ${macros.primary_header_defaults(4)},
      "data": {
        "user_data": {
          "src_data": {
            "function_id": 10
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks(start=1)},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  }
]}