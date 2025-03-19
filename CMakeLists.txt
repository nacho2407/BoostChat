cmake_minimum_required(VERSION 3.14)

project(
        BoostChat
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED BOOST_ROOT)
        message(FATAL_ERROR "Boost C++ Libraries directory's not defined!\nPlease define Boost directory: -DBOOST_ROOT=<absolute path to Boost>")
endif()

set(BOOST_INCLUDE_DIR ${BOOST_ROOT})

if(NOT DEFINED BOOST_LIBRARY_DIR)
        set(BOOST_LIBRARY_DIR "${BOOST_ROOT}/stage/lib")
endif()

set(CMAKE_INSTALL_RPATH "$ORIGIN;${BOOST_LIBRARY_DIR}")

add_subdirectory(server)
