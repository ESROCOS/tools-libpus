# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# The PUS library is particularized for each application/mission with a set of definitions
# for housekeeping parameters, events, etc. For each subdirectory in mission, an instance 
# of the PUS library is created. This file finds and processes all the subdirectories.


# Process all subdirectories

file(GLOB CONTENTS *)
foreach(F ${CONTENTS})
    if(IS_DIRECTORY ${F})
        message(STATUS "Adding mission configuration directory ${F}")
        add_subdirectory(${F})
    endif()
endforeach(F)
