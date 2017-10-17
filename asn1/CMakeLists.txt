if (NOT DEFINED ENV{ASN1SCC})
    message(FATAL_ERROR "Environment variable ASN1SCC not set. Load TASTE environment.")
endif()

set(ASN1
    ccsds_packet.asn
    ccsds_packet_fields.asn
    pus_config.asn
    pus_nbit_integers.asn
    pus_services.asn
    pus_st01.asn
    pus_st03.asn
    pus_time.asn
)

file(GLOB ASN1_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/*.asn")
set(ASN1_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated/asn1")
file(MAKE_DIRECTORY ${ASN1_OUT_DIR})

# Run the .c generation, so that FILE(GLOB ...) will 
execute_process(
    COMMAND mono $ENV{ASN1SCC} -c -typePrefix asn1Scc -uPER -wordSize 8 -ACN -o ${ASN1_OUT_DIR} -atc ${ASN1_PATHS}
    RESULT_VARIABLE ASN1SCC_RESULT
)

if(${ASN1SCC_RESULT} EQUAL 0)
    message(STATUS "ASN.1 first compilation successful.")
else()
    message(FATAL_ERROR "ASN.1 first compilation failed.")
endif()


# Command for asn.1 compilation; creates timestamp file
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/pus-asn1-stamp
    COMMAND mono $ENV{ASN1SCC} -c -typePrefix asn1Scc -uPER -wordSize 8 -ACN -o ${ASN1_OUT_DIR} -atc ${ASN1_PATHS}
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/pus-asn1-stamp
    DEPENDS ${ASN1}
    COMMENT "Generate header files for: ${ASN1_PATHS} in ${ASN1_OUT_DIR}"
)


# Target for asn.1 compilation; uses stamp file to run dependent targets only if changed
add_custom_target(
    asn1_generate_c
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/pus-asn1-stamp
)

# Add asn1 folder with generated C code
#add_subdirectory(generated)

# Common files created by the ASN.1 compiler
set(ASN1SCC_COMMON
    ${ASN1_OUT_DIR}/acn.c
    ${ASN1_OUT_DIR}/asn1crt.c
    ${ASN1_OUT_DIR}/real.c
)

# Test files created by the ASN.1 compiler
set(ASN1SCC_TEST
    ${ASN1_OUT_DIR}/testsuite.c
    ${ASN1_OUT_DIR}/testsuite.h
    ${ASN1_OUT_DIR}/mainprogram.c
)

# Get generated .c files 
file(GLOB C_FILES "${ASN1_OUT_DIR}/*.c")

set(SOURCES "")

foreach(cFile ${C_FILES})
    get_filename_component(fName ${cFile} NAME)
    if(NOT ${fName} IN_LIST ASN1SCC_COMMON AND NOT ${fName} IN_LIST ASN1SCC_TEST)
        list(APPEND SOURCES ${cFile})
    endif()
endforeach()

# Define the types library
add_library(esrocos_pus_asn1 STATIC ${SOURCES})
set_target_properties(esrocos_pus_asn1 PROPERTIES LINKER_LANGUAGE C)
add_dependencies(esrocos_pus_asn1 asn1_generate_c)
add_coverage(esrocos_pus_asn1)


# Create a library with the common .c files
add_library(esrocos_pus_asn1common STATIC ${ASN1SCC_COMMON})
set_target_properties(esrocos_pus_asn1common PROPERTIES LINKER_LANGUAGE C)
add_dependencies(esrocos_pus_asn1common asn1_generate_c)
add_coverage(esrocos_pus_asn1common)

# Unit tests executable
add_executable(test_asn1 ${ASN1_OUT_DIR}/mainprogram.c ${ASN1_OUT_DIR}/testsuite.c)
target_link_libraries(test_asn1 esrocos_pus_asn1 esrocos_pus_asn1common)
add_coverage(test_asn1)

