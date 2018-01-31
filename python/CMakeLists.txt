# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Python source files
file(GLOB PYTHON_SCRIPTS *.py)

# Python packages
add_subdirectory(pus_config)

# Target to redo stuff if Python scripts change
add_custom_target(
    python_scripts
    DEPENDS ${PYTHON_SCRIPTS} python_pus_config
)

