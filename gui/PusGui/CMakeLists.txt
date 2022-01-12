# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2


file(GLOB PYTHON_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.py")

# Copy *.py files to build folder
foreach(F ${PYTHON_SRC})
    configure_file(${F} ${F} COPYONLY)
endforeach()


add_subdirectory(Controller)
add_subdirectory(Model)
add_subdirectory(Utilities)
add_subdirectory(Views)


# Install source Python and JSON files
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/python/
    FILES_MATCHING 
    PATTERN "__pycache__" EXCLUDE
    PATTERN "*\.py"
    PATTERN "*\.json"
)

# Install generated (from PySide2 .ui files) Python files
install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/python/
    FILES_MATCHING 
    PATTERN "CMakeFiles" EXCLUDE
    PATTERN "*.py"
)
