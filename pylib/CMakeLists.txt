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
set_target_properties(${LIBPUS_MISSION}_py PROPERTIES 
    OUTPUT_NAME ${LIBPUS_MISSION}
    COMPILE_DEFINITIONS "ESROCOS_PYMODULE_NAME=${LIBPUS_MISSION}"
    LINKER_LANGUAGE CXX
)
target_link_libraries(${LIBPUS_MISSION}_py PUBLIC ${LIBPUS_MISSION} ${LIBPUS_MISSION}_types)



#
# Installation
#

install(TARGETS ${LIBPUS_MISSION}_py
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib/python)

# Create symlink to library, removing Python version suffix
install_symlink(${LIBPUS_MISSION}_py${PYTHON_MODULE_EXTENSION} ${CMAKE_INSTALL_PREFIX}/lib/python/${LIBPUS_MISSION}_py.so)
