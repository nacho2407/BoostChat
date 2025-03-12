cmake_minimum_required(VERSION 3.14)

project(
        BoostChat
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(server)

install(
        TARGETS BoostChat_server logger message server session
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
)
