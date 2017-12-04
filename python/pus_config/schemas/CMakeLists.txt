# JSON schema files
set(JSON_SCHEMAS
    st03_st12_schema.json
    st05_schema.json
    st08_schema.json
    st19_schema.json
    packet_queues_schema.json
)

# Target to add dependencies on the schemas
add_custom_target(
    python_pus_config_schemas
    DEPENDS ${JSON_SCHEMAS}
)

