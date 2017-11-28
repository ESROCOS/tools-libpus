# Source files
set(SOURCES
	pus_binding.cpp
) # Duda he de poner aqui 


# Define the PUS library
pybind11_add_module(pusbinding  ${SOURCES})
set_target_properties(pusbinding PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(pusbinding PRIVATE esrocos_pus PRIVATE esrocos_pus_asn1 PRIVATE esrocos_pus_asn1common)



