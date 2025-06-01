cmake_minimum_required(VERSION 3.25)

project(
        BoostChat
        VERSION build
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(BOOST_CHAT_INSTALL_PATH "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory(server)
