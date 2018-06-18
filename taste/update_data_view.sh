export FILES="
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/ccsds_packet.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/ccsds_packet_fields.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_config.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_types_definitions.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_services.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st01.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st03.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st05.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st08.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st09.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st12.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st18.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st19.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st20.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_st23.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/test_01/pus_time.asn \
/home/esrocos/tool-inst/share/taste-types/taste-types.asn "
echo "Updating DataView.aadl"
taste-update-data-view $FILES


