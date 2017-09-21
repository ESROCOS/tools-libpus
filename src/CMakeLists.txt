# Source files
set(SOURCES
    pus.c
)

# Define the PUS library
add_library(esrocos_pus STATIC ${SOURCES})

# Specify linker
set_target_properties(esrocos_pus PROPERTIES LINKER_LANGUAGE C)

# Depends on the library with the types generated from ASN.1
add_dependencies(esrocos_pus esrocos_pus_asn1)

