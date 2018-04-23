# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Source files
set(SOURCES
	pus_binding.cpp
	pus_bindingfunctions.cpp
)


# Define the PUS library
pybind11_add_module(${LIBPUS_MISSION}_py ${SOURCES})
set_target_properties(${LIBPUS_MISSION}_py PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${LIBPUS_MISSION}_py PUBLIC ${LIBPUS_MISSION})



