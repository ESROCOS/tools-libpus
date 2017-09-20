if (NOT DEFINED ENV{ASN1SCC})
    message(FATAL_ERROR "Environment variable ASN1SCC not set. Load TASTE environment.")
endif()

set(ASN1
    ccsds_packet.asn
    pus_nbit_integers.asn
    pus_services.asn
    pus_st01.asn
    pus_time.asn
)

file(GLOB ASN1_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/*.asn")
set(ASN1_HEADERS_DIR "${CMAKE_SOURCE_DIR}/include/asn1")

# Command for asn.1 compilation; creates timestamp file
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/pus-asn1-stamp
    COMMAND mkdir -p ${ASN1_HEADERS_DIR}
    COMMAND mono $ENV{ASN1SCC} -c -typePrefix asn1Scc -o ${ASN1_HEADERS_DIR} ${ASN1_PATHS}
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/pus-asn1-stamp
    DEPENDS ${ASN1}
    COMMENT "Generate header files for: ${ASN1_PATHS} in ${ASN1_HEADERS_DIR}"
)


# Target for asn.1 compilation; uses stamp file to run only if changed
add_custom_target(
    asn1_generate_headers
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/pus-asn1-stamp
)
