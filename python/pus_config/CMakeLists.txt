# Package files
set(PYTHON_SCRIPTS
    __init__.py
    mission_config.py
    packet_queues_config.py
    st03_config.py
    st05_config.py
    st08_config.py
    st11_config.py 
    st12_config.py 
    st19_config.py  
)

# Subdirectories
add_subdirectory(schemas)
add_subdirectory(templates)

# Target to add dependencies on the schemas
add_custom_target(
    python_pus_config
    DEPENDS ${PYTHON_SCRIPTS} python_pus_config_schemas python_pus_config_templates
)

