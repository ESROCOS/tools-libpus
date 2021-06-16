export FILES="
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/ccsds_packet.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/ccsds_packet_fields.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_config.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_types_definitions.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_services.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st01.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st03.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st05.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st08.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st09.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st12.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st18.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st19.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st20.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st23.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_time.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st200.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st200_Trex_to_Taste_Dataview.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st210.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st220.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/pus/mosar/pus_st_ext.asn \
/home/esrocos/tool-inst/share/taste-types/taste-types.asn "
echo "Updating DataView.aadl"
taste-update-data-view $FILES


