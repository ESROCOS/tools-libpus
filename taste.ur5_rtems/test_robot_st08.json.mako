{ "activities": [
  {
    "interval": 0,
    "action": "setfilter",
    "params": {"type": "", "svc": [8, 20, 201], "msg": 0}
  },
  {
    "interval": 0,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "param_id": ${UR5_HOME_POS_1},
            "value": 0.3
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_HOME_POS_2},
            "value": 0.12
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_HOME_POS_3},
            "value": 0.71
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  }
  ,
  {
    "interval": 1,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "param_id": ${UR5_HOME_ORI_1},
            "value": 0.58
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_HOME_ORI_2},
            "value": 0.45
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_HOME_ORI_3},
            "value": 0.54
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_HOME_ORI_RE},
            "value": 0.4
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "function_id": ${UR5_SETHOME}
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
    {
    "interval": 5,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "param_id": ${UR5_MOVE_POS_1},
            "value": 0.3
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_MOVE_POS_2},
            "value": 0.11
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_MOVE_POS_3},
            "value": 0.37
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  }
  ,
  {
    "interval": 1,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "param_id": ${UR5_MOVE_ORI_1},
            "value": 0.53
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_MOVE_ORI_2},
            "value": 0.46
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_MOVE_ORI_3},
            "value": 0.53
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "param_id": ${UR5_MOVE_ORI_RE},
            "value": 0.46
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(20, 3)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
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
            "function_id": ${UR5_PLANMOVE}
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 5,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "function_id": ${UR5_PLANHOME}
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 5,
    "packet": {
      ${macros.primary_header_defaults()},
      "data": {
        "user_data": {
          "src_data": {
            "function_id": ${CAMERA_FRAMEREQUEST}
          }
        },
        "pck_sec_head": {
          ${macros.tc_type(8, 1)},
          ${macros.acks()},
          "src_id": 1,
          "tc_packet_pus_version_number": 2
        }
      }
    }
  },
  {
    "interval": 1,
    "action": "savedb",
    "params": "dump_test_robot.db"
  }
]}