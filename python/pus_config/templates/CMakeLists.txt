# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Mako template files
set(MAKO_TEMPLATES
	pus_packet_queues_config.c.mako
    pus_packet_queues_config.h.mako
    pus_st03_config.c.mako
    pus_st03_config.h.mako
    pus_st05_config.c.mako
    pus_st05_config.h.mako
    pus_st08_config.c.mako
    pus_st08_config.h.mako
    pus_st11_config.c.mako
    pus_st11_config.h.mako
    pus_st12_config.c.mako
    pus_st12_config.h.mako
  	pus_st19_config.c.mako
    pus_st19_config.h.mako
    
)

# Target to add dependencies on the templates
add_custom_target(
    python_pus_config_templates
    DEPENDS ${MAKO_TEMPLATES}
)

