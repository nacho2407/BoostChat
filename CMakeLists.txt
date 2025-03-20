cmake_minimum_required(VERSION 3.25)

project(
        BoostChat
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

set(BC_INSTALL_PATH "${CMAKE_SOURCE_DIR}/bin/server")

find_package(Boost REQUIRED COMPONENTS serialization system)

file(GLOB BC_BOOST_SERIALIZATION "${Boost_LIBRARY_DIRS}/*boost_serialization*")
file(GLOB BC_BOOST_SYSTEM "${Boost_LIBRARY_DIRS}/*boost_system*")

install(
        FILES ${BC_BOOST_SERIALIZATION} ${BC_BOOST_SYSTEM}
        DESTINATION ${BC_INSTALL_PATH}
)

add_subdirectory(server)
