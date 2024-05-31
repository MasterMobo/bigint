project(BigInt)

file(GLOB_RECURSE bigint_SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp)

add_library(bigint ${bigint_SRC})

target_include_directories(bigint 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)