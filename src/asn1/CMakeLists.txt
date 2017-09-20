# Compile all generated .c files
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

message(STATUS ${SOURCES})

# Define the library
add_library(esrocos_pus_asn1 STATIC ${SOURCES})

# Specify linker
set_target_properties(esrocos_pus_asn1 PROPERTIES LINKER_LANGUAGE C)

# Depends on the compilation of the ASN.1 files
add_dependencies(esrocos_pus_asn1 asn1_compile_c)

