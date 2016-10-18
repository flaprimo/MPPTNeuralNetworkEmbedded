add_library(StellarisWare)

add_subdirectory(driverlib)
add_subdirectory(inc)

set_target_properties(StellarisWare PROPERTIES LINKER_LANGUAGE C)