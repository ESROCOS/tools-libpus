# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2


# PySide2 UI files
file(GLOB PYSIDE_UI RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.ui")

# Generate *.py from *.ui
foreach(F ${PYSIDE_UI})
    get_filename_component(FNAME ${F} NAME_WE)
    list(APPEND PYTHON_GEN ${FNAME}.py)
    add_custom_command(
        OUTPUT ${FNAME}.py
        COMMAND pyside2-uic -o ${FNAME}.py ${CMAKE_CURRENT_SOURCE_DIR}/${F} 
        COMMENT "Generate Python code for ${F}"
    )
endforeach()

add_custom_target(pyside_generated ALL DEPENDS ${PYTHON_GEN})

