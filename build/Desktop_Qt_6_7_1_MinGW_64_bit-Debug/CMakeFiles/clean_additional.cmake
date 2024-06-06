# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\IDEnsamblador_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\IDEnsamblador_autogen.dir\\ParseCache.txt"
  "IDEnsamblador_autogen"
  )
endif()
