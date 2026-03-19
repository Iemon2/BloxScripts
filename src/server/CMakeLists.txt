file(GLOB_RECURSE SERVER_SOURCES CONFIGURE_DEPENDS *.c)

add_library(server STATIC ${SERVER_SOURCES})

target_include_directories(server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(server PRIVATE ${enet_SOURCE_DIR}/include)

target_link_libraries(server INTERFACE enet)