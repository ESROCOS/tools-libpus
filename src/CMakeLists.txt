# Source files
set(SOURCES
    pus_error.c
    pus_packet.c
    pus_time.c
    pus_types.c
)

# Define the PUS library
add_library(esrocos_pus STATIC ${SOURCES})
set_target_properties(esrocos_pus PROPERTIES LINKER_LANGUAGE C)
add_dependencies(esrocos_pus esrocos_pus_asn1)


# Test executable
add_executable(esrocos_pus_test main.c)
target_link_libraries(esrocos_pus_test
    esrocos_pus
    esrocos_pus_asn1
    esrocos_pus_asn1common
)
add_dependencies(esrocos_pus_test
    esrocos_pus
    esrocos_pus_asn1
    esrocos_pus_asn1common
)
