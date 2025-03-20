cmake_minimum_required(VERSION 3.25)

project(
        BoostChat
        VERSION "build"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(client)
add_subdirectory(server)
