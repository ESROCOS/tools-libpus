# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2


# Preinstall headers and libraries for first build
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)
esrocos_preinstall_files(pus_headers include/pus ${HEADERS})

file(GLOB JSON_HEADERS ${CMAKE_BINARY_DIR}/mission/test_01/generated/include/*.h)
esrocos_preinstall_files(pus_mission_headers include/pus/mission/test_01 ${JSON_HEADERS} ${CMAKE_SOURCE_DIR}/mission/test_01/pus_enable_services.h)

esrocos_preinstall_files(pus_libs lib 
    ${CMAKE_BINARY_DIR}/mission/test_01/pus/libesrocos_pus_core_test_01.so
    ${CMAKE_BINARY_DIR}/mission/test_01/mpy/libesrocos_mpy_core_test_01.so
    ${CMAKE_BINARY_DIR}/mission/test_01/libesrocos_pus_test_01.so
)


esrocos_build_taste(pus_test_01
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
    trigger
    BINARIES
    binary.c/binaries/x86_partition
    DEPENDS
    pus_headers
    pus_mission_headers
    pus_libs
    esrocos_pus_test_01
    esrocos_pus_core_test_01
)



