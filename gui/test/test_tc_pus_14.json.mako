{ "activities": [
  {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [23,1], "msg": 0}
  },
  {
    "interval": 0,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
              "file_name": "test.txt",
              "repo_path": "PUS_REPOSITORY_TEST",
              "max_size": 200
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(23, 1)},
          "src_id": 1,
          ${macros.acks(completion=1)},
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
          "src_data": {
            "target_file": "test2.txt",
            "source_file": "test.txt",
            "source_repository": "PUS_REPOSITORY_TEST",
            "target_repository": "PUS_REPOSITORY_TEST"
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(23, 14)},
          "src_id": 1,
          ${macros.acks(completion=1)},
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
          "src_data": {
              "file_name": "test.txt",
              "repo_path": "PUS_REPOSITORY_TEST"          
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(23, 3)},
          "src_id": 1,
          ${macros.acks(completion=1)},
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 6,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
              "file_name": "test.txt",
              "repo_path": "PUS_REPOSITORY_TEST"          
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(23, 2)},
          "src_id": 1,
          ${macros.acks(completion=1)},
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
          "src_data": {
              "file_name": "test2.txt",
              "repo_path": "PUS_REPOSITORY_TEST"          
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(23, 2)},
          "src_id": 1,
          ${macros.acks(completion=1)},
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 1,
    "action": "savedb",
    "params": "dump_test_st14.db"
  }
]}