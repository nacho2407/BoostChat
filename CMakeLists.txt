cmake_minimum_required(VERSION 3.14)

project(
        BoostChat
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

if(NOT BOOST_ROOT)
        message(FATAL_ERROR "Boost C++ Libraries directory's not defined!\nPlease define Boost directory: -DBOOST_ROOT=<absolute path to Boost>")
endif()

set(BOOST_INCLUDE_DIR ${BOOST_ROOT})

if(NOT BOOST_LIBRARY_DIR)
        set(BOOST_LIBRARY_DIR ${BOOST_ROOT}/stage/lib)
endif()

set(CMAKE_INSTALL_RPATH $ORIGIN;${BOOST_LIBRARY_DIR})

add_subdirectory(server)

install(
        TARGETS bc_logger bc_server BoostChat_server
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/bin
        ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib
)
