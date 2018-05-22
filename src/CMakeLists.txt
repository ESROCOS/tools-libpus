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

# Static
add_library(esrocos_pus_static_aux_${MISSION} STATIC ${SOURCES})
set_target_properties(esrocos_pus_static_aux_${MISSION} PROPERTIES OUTPUT_NAME esrocos_pus_aux_${MISSION})
target_link_libraries(esrocos_pus_static_aux_${MISSION} 
    esrocos_mpy_static_aux_${MISSION}
    ${LIBPUS_MISSION}_static
    ${CMAKE_THREAD_LIBS_INIT}
)
set_target_properties(esrocos_pus_static_aux_${MISSION} PROPERTIES 
    LINKER_LANGUAGE C
    POSITION_INDEPENDENT_CODE TRUE
)
target_include_directories(esrocos_pus_static_aux_${MISSION} PUBLIC ${CMAKE_BINARY_DIR}/asn1 ${CMAKE_SOURCE_DIR}/mission/${MISSION}/)
add_coverage(esrocos_pus_static_aux_${MISSION})

# Shared
add_library(esrocos_pus_aux_${MISSION} SHARED ${SOURCES})
target_link_libraries(esrocos_pus_aux_${MISSION} 
    esrocos_mpy_aux_${MISSION} 
    ${CMAKE_THREAD_LIBS_INIT}
)
set_target_properties(esrocos_pus_aux_${MISSION} PROPERTIES 
    LINKER_LANGUAGE C
    POSITION_INDEPENDENT_CODE TRUE
)
target_include_directories(esrocos_pus_aux_${MISSION} PUBLIC ${CMAKE_BINARY_DIR}/asn1 ${CMAKE_SOURCE_DIR}/mission/${MISSION}/)
add_coverage(esrocos_pus_aux_${MISSION})


#
# Installation
#

install(TARGETS esrocos_pus_aux_${MISSION} esrocos_pus_static_aux_${MISSION}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)


# Define the PUS library with threads disabled
#add_library(esrocos_pus_nothreads SHARED ${SOURCES})
#set_target_properties(esrocos_pus_nothreads PROPERTIES LINKER_LANGUAGE C)
#set_target_properties(esrocos_pus_nothreads PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
#target_include_directories(esrocos_pus PUBLIC ${CMAKE_BINARY_DIR}/asn1)
#target_compile_options(esrocos_pus_nothreads PUBLIC -DPUS_DISABLE_THREADS)
#add_coverage(esrocos_pus_nothreads)

#add_library(esrocos_pus_nothreads2 OBJECT ${SOURCES})
#set_target_properties(esrocos_pus_nothreads2 PROPERTIES LINKER_LANGUAGE C)




