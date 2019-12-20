# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Name of the reusable TASTE component
set(COMPONENT_NAME "taste_pus_02")


# Preinstall ASN.1 types, headers and libraries for first build
file(GLOB ASN1 ${CMAKE_SOURCE_DIR}/asn1/*.asn)
esrocos_preinstall_files(pus_asn1_${COMPONENT_NAME} types/pus/${MISSION} ${ASN1})

file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)
esrocos_preinstall_files(pus_headers_${COMPONENT_NAME} include/pus ${HEADERS})

file(GLOB JSON_HEADERS ${CMAKE_BINARY_DIR}/mission/test_01/generated/include/*.h)
esrocos_preinstall_files(pus_mission_headers_${COMPONENT_NAME} include/pus/mission/test_01 ${JSON_HEADERS} ${CMAKE_SOURCE_DIR}/mission/test_01/pus_enable_services.h ${CMAKE_SOURCE_DIR}/mission/test_01/pus_mission_types.h)

esrocos_preinstall_directories(mpy_headers_${COMPONENT_NAME} include/pus/mission/test_01/mpy ${CMAKE_BINARY_DIR}/mission/test_01/mpy/include)

esrocos_preinstall_files(pus_libs_${COMPONENT_NAME} lib
    ${CMAKE_BINARY_DIR}/mission/test_01/pus/libesrocos_pus_core_test_01.so
    ${CMAKE_BINARY_DIR}/mission/test_01/mpy/libesrocos_mpy_core_test_01.so
    ${CMAKE_BINARY_DIR}/mission/test_01/libesrocos_pus_test_01.so
)


esrocos_build_taste(${COMPONENT_NAME}
    SOURCES
    events
    filemanagement
    ground
    housekeeping
    onboardapid
    onboardparams
    onboardsoftware
    st01
    st03
    st05
    st08
    st09
    st11
    st12
    st17
    st18
    st19
    st20
    st23
    tcdispatch
    tcqueue
    timereportapid
    tmdispatch
    tmqueue
    BINARIES
    binary.c/binaries/x86_partition
    DEPENDS
    pus_asn1_${COMPONENT_NAME}
    pus_headers_${COMPONENT_NAME}
    pus_mission_headers_${COMPONENT_NAME}
    mpy_headers_${COMPONENT_NAME}
    pus_libs_${COMPONENT_NAME}
    esrocos_pus_test_01
    esrocos_pus_core_test_01
    esrocos_mpy_core_test_01
)



