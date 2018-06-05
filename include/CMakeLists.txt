# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

set(HEADERS
    pus_apid.h
    pus_error.h
    pus_event_action.h
    pus_events.h
    pus_file_management.h
    pus_housekeeping.h
    pus_notify.h
    pus_obcp_engine.h
    pus_packet.h
    pus_packet_queues.h
    pus_packet_reduced.h
    pus_parameter_management.h
    pus_parameter_monitoring.h
    pus_st01_packets.h
    pus_st03_packets.h
    pus_st05_packets.h
    pus_st08_packets.h
    pus_st09_packets.h
    pus_st11_packets.h
    pus_st12_packets.h
    pus_st17_packets.h
    pus_st18_packets.h
    pus_st19_packets.h
    pus_st20_packets.h
    pus_st23_packets.h
    pus_stored_param.h
    pus_threads.h
    pus_timebased_scheduling.h
    pus_time.h
    pus_types.h
)


# Install headers
install(FILES ${HEADERS} DESTINATION include/pus)
