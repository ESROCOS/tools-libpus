# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Name of the reusable TASTE component
set(COMPONENT_NAME "taste_pus")


# Preinstall ASN.1 types, headers and libraries for first build
file(GLOB ASN1 ${CMAKE_SOURCE_DIR}/asn1/*.asn)
esrocos_preinstall_files(pus_asn1_${COMPONENT_NAME} types/pus/${MISSION} ${ASN1})

file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)
esrocos_preinstall_files(pus_headers_${COMPONENT_NAME} include/pus ${HEADERS})

file(GLOB JSON_HEADERS ${CMAKE_BINARY_DIR}/mission/test_01/generated/include/*.h)
esrocos_preinstall_files(pus_mission_headers_${COMPONENT_NAME} include/pus/mission/${MISSION} ${JSON_HEADERS} ${CMAKE_SOURCE_DIR}/mission/${MISSION}/pus_enable_services.h ${CMAKE_SOURCE_DIR}/mission/${MISSION}/pus_mission_types.h)

esrocos_preinstall_directories(mpy_headers_${COMPONENT_NAME} include/pus/mission/${MISSION}/mpy ${CMAKE_BINARY_DIR}/mission/${MISSION}/mpy/include)

esrocos_preinstall_files(pus_libs_${COMPONENT_NAME} lib
    ${CMAKE_BINARY_DIR}/mission/${MISSION}/pus/libesrocos_pus_core_${MISSION}.so
    ${CMAKE_BINARY_DIR}/mission/${MISSION}/mpy/libesrocos_mpy_core_${MISSION}.so
    ${CMAKE_BINARY_DIR}/mission/${MISSION}/libesrocos_pus_${MISSION}.so
)


esrocos_build_taste(${COMPONENT_NAME}
    SOURCES
    ground
    pusservices
    onboardsw
    dummyprivateservice
    BINARIES
    work/binaries/x86_partition
#    DEPENDS
#    pus_asn1_${COMPONENT_NAME}
#    pus_headers_${COMPONENT_NAME}
#    pus_mission_headers_${COMPONENT_NAME}
#    mpy_headers_${COMPONENT_NAME}
#    pus_libs_${COMPONENT_NAME}
    #esrocos_pus_test_01
    #esrocos_pus_core_test_01
    #esrocos_mpy_core_test_01
)



