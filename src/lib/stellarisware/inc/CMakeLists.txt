file(GLOB SOURCES *.c *.h)
add_library(inc ${SOURCES})

set_target_properties(inc PROPERTIES LINKER_LANGUAGE C)