file(GLOB_RECURSE CLIENT_SOURCES CONFIGURE_DEPENDS *.c)

add_library(client STATIC ${CLIENT_SOURCES})

target_include_directories(client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(client PRIVATE ${enet_SOURCE_DIR}/include)

target_link_libraries(client INTERFACE enet)