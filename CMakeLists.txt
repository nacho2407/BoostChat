cmake_minimum_required(VERSION 3.1)

project(
    boost-chat
    VERSION build
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_CHAT_INSTALL_PATH ${CMAKE_SOURCE_DIR}/bin)
set(BOOST_CHAT_SHARED ${CMAKE_SOURCE_DIR}/shared)

set(EXT_LIBS ${CMAKE_SOURCE_DIR}/external)

find_library(BOOST_SYSTEM boost_system PATHS ${EXT_LIBS}/lib REQUIRED)
find_library(BOOST_SERIALIZATION boost_serialization PATHS ${EXT_LIBS}/lib REQUIRED)

add_subdirectory(server)
