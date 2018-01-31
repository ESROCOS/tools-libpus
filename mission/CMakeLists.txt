# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Process all subdirectories
file(GLOB CONTENTS *)

foreach(F ${CONTENTS})
    if(IS_DIRECTORY ${F})
        message(STATUS "Adding mission configuration directory ${F}")
        add_subdirectory(${F})
    endif()
endforeach(F)
