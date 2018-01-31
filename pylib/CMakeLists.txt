# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Source files
set(SOURCES
	pus_binding.cpp
	pus_bindingfunctions.cpp
) # Duda he de poner aqui


# Define the PUS library
pybind11_add_module(pusbinding  ${SOURCES})
set_target_properties(pusbinding PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(pusbinding PRIVATE esrocos_pus PRIVATE esrocos_pus_asn1 PRIVATE esrocos_pus_asn1common PRIVATE esrocos_pus_mission_test_01)



