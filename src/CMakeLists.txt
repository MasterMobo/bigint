project(BigInt)

file(GLOB_RECURSE bigint_SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp)
file(GLOB_RECURSE bigint_HDS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.h)

add_library(bigint ${bigint_SRC} ${bigint_HDS})

target_include_directories(bigint 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)