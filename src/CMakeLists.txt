# Source files
set(SOURCES
	pus_apid.c
    pus_error.c
    pus_packet.c
    pus_st01.c
    pus_st03.c
    pus_threads.c
    pus_time.c
)

# Define the PUS library
add_library(esrocos_pus STATIC ${SOURCES})
set_target_properties(esrocos_pus PROPERTIES LINKER_LANGUAGE C)
add_dependencies(esrocos_pus esrocos_pus_asn1)
add_coverage(esrocos_pus)

# Define the PUS library with threads disabled
add_library(esrocos_pus_nothreads STATIC ${SOURCES})
set_target_properties(esrocos_pus_nothreads PROPERTIES LINKER_LANGUAGE C)
target_compile_options(esrocos_pus_nothreads PUBLIC -DPUS_DISABLE_THREADS)
add_dependencies(esrocos_pus_nothreads esrocos_pus_asn1)
add_coverage(esrocos_pus_nothreads)


