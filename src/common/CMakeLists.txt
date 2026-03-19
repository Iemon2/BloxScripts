file(GLOB_RECURSE COMMON_SOURCES CONFIGURE_DEPENDS *.c)

add_library(common STATIC ${COMMON_SOURCES})
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(common PUBLIC ${enet_SOURCE_DIR}/include)
target_link_libraries(common INTERFACE enet)