# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Source files
set(SOURCES
    pus_apid.c
    pus_error.c
    pus_event_action.c
    pus_events.c
    pus_file_management.c
    pus_housekeeping.c
    pus_obcp_engine.c
    pus_notify.c
    pus_packet_reduced.c
    pus_packet_queues.c
    pus_packet.c
    pus_parameter_management.c
    pus_parameter_monitoring.c
    pus_st01_packets.c
    pus_st03_packets.c
    pus_st05_packets.c
    pus_st08_packets.c
    pus_st09_packets.c
    pus_st11_packets.c
    pus_st12_packets.c
    pus_st17_packets.c
    pus_st18_packets.c    
    pus_st19_packets.c
    pus_st20_packets.c
    pus_st23_packets.c
    pus_stored_param.c
    pus_threads.c
    pus_time.c
    pus_timebased_scheduling.c
)


#
# Define the PUS library 
#

if(CMAKE_CROSSCOMPILING)
    # Find libraries in ESROCOS' target-specific directory
    link_directories(${CMAKE_INSTALL_PREFIX}/${RTEMS_TARGET}/lib)
else()
    # Find libraries in ESROCOS' regular directory
    link_directories(${CMAKE_INSTALL_PREFIX}/lib)
endif()

# Static
add_library(esrocos_pus_static_core_${MISSION} STATIC ${SOURCES})
set_target_properties(esrocos_pus_static_core_${MISSION} PROPERTIES OUTPUT_NAME esrocos_pus_core_${MISSION})
target_link_libraries(esrocos_pus_static_core_${MISSION} 
    esrocos_mpy_static_core_${MISSION}
    ${LIBPUS_MISSION}_static
    ${CMAKE_THREAD_LIBS_INIT}
)
set_target_properties(esrocos_pus_static_core_${MISSION} PROPERTIES 
    LINKER_LANGUAGE C
    POSITION_INDEPENDENT_CODE TRUE
)
target_include_directories(esrocos_pus_static_core_${MISSION} PUBLIC ${CMAKE_BINARY_DIR}/mission/${MISSION}/asn1/esrocos_pustypes_${MISSION} ${CMAKE_SOURCE_DIR}/mission/${MISSION}/)

if(NOT CMAKE_CROSSCOMPILING)
    add_coverage(esrocos_pus_static_core_${MISSION})
endif()

# Shared (native build only)
if(NOT CMAKE_CROSSCOMPILING)
    add_library(esrocos_pus_core_${MISSION} SHARED ${SOURCES})
    target_link_libraries(esrocos_pus_core_${MISSION} 
        esrocos_mpy_core_${MISSION} 
        ${CMAKE_THREAD_LIBS_INIT}
    )
    set_target_properties(esrocos_pus_core_${MISSION} PROPERTIES 
        LINKER_LANGUAGE C
        POSITION_INDEPENDENT_CODE TRUE
    )
    target_include_directories(esrocos_pus_core_${MISSION} PUBLIC ${CMAKE_BINARY_DIR}/mission/${MISSION}/asn1/esrocos_pustypes_${MISSION} ${CMAKE_SOURCE_DIR}/mission/${MISSION}/)
    add_coverage(esrocos_pus_core_${MISSION})
endif()


#
# Installation
#

if(CMAKE_CROSSCOMPILING)
    set(TARGET_INSTALL_PREFIX "${RTEMS_TARGET}/")
    set(TARGETS_TO_INSTALL esrocos_pus_static_core_${MISSION})
else()
    set(TARGET_INSTALL_PREFIX "")
    set(TARGETS_TO_INSTALL esrocos_pus_core_${MISSION} esrocos_pus_static_core_${MISSION})
endif()

install(TARGETS ${TARGETS_TO_INSTALL}
    RUNTIME DESTINATION "${TARGET_INSTALL_PREFIX}bin"
    LIBRARY DESTINATION "${TARGET_INSTALL_PREFIX}lib"
    ARCHIVE DESTINATION "${TARGET_INSTALL_PREFIX}lib"
)


