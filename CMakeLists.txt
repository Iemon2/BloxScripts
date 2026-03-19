cmake_minimum_required(VERSION 4.1.1)
project(BloxScripts VERSION 0.0.1)

set(CMAKE_C_STANDARD 17)


# Subdirectories
add_subdirectory("include/thirdparty/enet-1.3.18")
add_subdirectory(src/app)
add_subdirectory(src/common)
add_subdirectory(src/client)
add_subdirectory(src/platform)
add_subdirectory(src/server)