# Process all subdirectories
file(GLOB CONTENTS *)

foreach(F ${CONTENTS})
    if(IS_DIRECTORY ${F})
        message(STATUS "Adding mission configuration directory ${F}")
        add_subdirectory(${F})
    endif()
endforeach(F)
