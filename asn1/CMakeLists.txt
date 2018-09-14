# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Create the C types for the PUS services from the ASN.1 definitions using the 
# ESROCOS macros for ASN.1 types. 
#
# See the esrocos.cmake file for details on the variables and targets created 
# to build the ASN.1 types.

esrocos_asn1_types_package(esrocos_pustypes_${MISSION}
    ${CCDS_PACKET_PATH_${MISSION}}ccsds_packet.asn
    ccsds_packet_fields.asn
    ${CONFIG_PATH_${MISSION}}pus_config.asn
    pus_types_definitions.asn
    ${SERVICES_PATH_${MISSION}}pus_services.asn
    pus_st01.asn
    pus_st03.asn
    pus_st05.asn
    pus_st08.asn
    pus_st12.asn
    pus_st09.asn
    pus_st19.asn
    pus_st18.asn
    pus_st20.asn
    pus_st23.asn
    pus_time.asn
    ${${MISSION}_ASN1}
)

esrocos_asn1_types_build_test(esrocos_pustypes_${MISSION})
esrocos_asn1_types_install(esrocos_pustypes_${MISSION} ${CMAKE_INSTALL_PREFIX}/types/pus/${MISSION})


