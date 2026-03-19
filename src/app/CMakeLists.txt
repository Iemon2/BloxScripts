file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS *.c)

add_executable(textChat ${APP_SOURCES})

target_include_directories(textChat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(textChat PRIVATE ${enet_SOURCE_DIR}/include)

target_link_libraries(textChat INTERFACE enet)