# JSON schema files
set(JSON_SCHEMAS
    st03_schema.json
)

# Target to add dependencies on the schemas
add_custom_target(
    python_pus_config_schemas
    DEPENDS ${JSON_SCHEMAS}
)

