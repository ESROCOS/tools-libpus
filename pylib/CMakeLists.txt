# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Source files
set(SOURCES
	pus_binding.cpp
	pus_bindingfunctions.cpp
	${PUS_BINDING_MISISON_${MISSION}}
)


pybind11_add_module(${LIBPUS_MISSION}_py ${SOURCES})
set_target_properties(${LIBPUS_MISSION}_py PROPERTIES 
    OUTPUT_NAME ${LIBPUS_MISSION}
    LINKER_LANGUAGE CXX
)

# Missionization pusbinding module
if(EXISTS "${CMAKE_SOURCE_DIR}/mission/${MISSION}/pus_binding_mission.cpp")
	target_compile_definitions(${LIBPUS_MISSION}_py PRIVATE ESROCOS_PYMODULE_NAME=${LIBPUS_MISSION} MISSION_BINDING=1)
else()
	target_compile_definitions(${LIBPUS_MISSION}_py PRIVATE ESROCOS_PYMODULE_NAME=${LIBPUS_MISSION})
endif()

target_link_libraries(${LIBPUS_MISSION}_py PUBLIC ${LIBPUS_MISSION} ${LIBPUS_MISSION}_types)



#
# Installation
#

install(TARGETS ${LIBPUS_MISSION}_py
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib/python)

# Create symlink to library, removing Python version suffix
install_symlink(${LIBPUS_MISSION}_py${PYTHON_MODULE_EXTENSION} ${CMAKE_INSTALL_PREFIX}/lib/python/${LIBPUS_MISSION}_py.so)
