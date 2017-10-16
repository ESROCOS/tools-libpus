# Mako template files
set(MAKO_TEMPLATES
    pus_st03_config.c.mako
    pus_st03_config.h.mako
)

# Target to add dependencies on the templates
add_custom_target(
    python_pus_config_templates
    DEPENDS ${MAKO_TEMPLATES}
)

