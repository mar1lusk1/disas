cmake_minimum_required(VERSION 3.10)
project(disas C)

set(CMAKE_C_STANDARD 99)

# Add the source files
set(SOURCES
    MAIN.c
    fileutils.c
)

# Add the header files for IDEs
set(HEADERS
    defs.h
    magic.h
    logging.h
    arch.h
    fileutils.h
    x86_64.h
)

add_executable(disas ${SOURCES} ${HEADERS})

target_include_directories(disas PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
