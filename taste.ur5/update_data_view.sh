export FILES="
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/ccsds_packet.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/ccsds_packet_fields.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_config.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_types_definitions.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_services.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st01.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st03.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st05.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st08.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st09.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st12.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st18.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st19.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st20.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st23.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_time.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st200.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_ur5/pus_st201.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/base/base.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/base/taste-extended.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/base/taste-types.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/base/userdefs-base.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/ur5_types/buffer.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/ur5_types/commandStates.asn \
/home/esrocos/tool-inst/share/taste-types/taste-types.asn "
echo "Updating DataView.aadl"

taste-update-data-view $FILES


