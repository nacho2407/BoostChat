cmake_minimum_required(VERSION 3.25)

project(
    boost-chat
    VERSION build
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_CHAT_INSTALL_PATH ${CMAKE_SOURCE_DIR}/bin)
set(BOOST_DIR ${CMAKE_SOURCE_DIR}/external/boost)

add_subdirectory(server)
