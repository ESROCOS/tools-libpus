

function(esrocos_taste_build MODEL_TARGET)

    set(MODEL_DIR "${CMAKE_CURRENT_BINARY_DIR}/model")

    file(COPY . DESTINATION ${MODEL_DIR})

    # Command for C compilation; creates timestamp file
    set(TIMESTAMP_FILE "${MODEL_DIR}/binary.c/timestamp")
    add_custom_command(OUTPUT ${TIMESTAMP_FILE}
        COMMAND pwd
        COMMAND "${MODEL_DIR}/build-script.sh"
        COMMAND ${CMAKE_COMMAND} -E touch ${TIMESTAMP_FILE}
        WORKING_DIRECTORY ${MODEL_DIR}
        COMMENT "Building TASTE model in ${MODEL_DIR}"
    )

    # Target for C compilation; uses stamp file to run dependent targets only if changed
    add_custom_target(
        ${MODEL_TARGET}
        DEPENDS ${TIMESTAMP_FILE}
    )

endfunction(esrocos_taste_build)



esrocos_taste_build(taste_t01)



