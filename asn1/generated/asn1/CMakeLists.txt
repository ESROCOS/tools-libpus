# Common files created by the ASN.1 compiler
set(ASN1SCC_COMMON
    acn.c
    asn1crt.c
    real.c
)

# Get generated .c files 
file(GLOB C_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

set(SOURCES "")

foreach(cFile ${C_FILES})
    get_filename_component(fName ${cFile} NAME)
    if(NOT ${fName} IN_LIST ASN1SCC_COMMON)
        list(APPEND SOURCES ${cFile})
    endif()
endforeach()


# Define the types library
add_library(esrocos_pus_asn1 STATIC ${SOURCES})
set_target_properties(esrocos_pus_asn1 PROPERTIES LINKER_LANGUAGE C)
add_dependencies(esrocos_pus_asn1 asn1_compile_c)


# Create a library with the common .c files
add_library(esrocos_pus_asn1common STATIC ${ASN1SCC_COMMON})
set_target_properties(esrocos_pus_asn1common PROPERTIES LINKER_LANGUAGE C)
add_dependencies(esrocos_pus_asn1common asn1_compile_c)

