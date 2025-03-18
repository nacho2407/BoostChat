add_library(bc_logger STATIC logger.cpp)

target_include_directories(bc_logger PUBLIC ${BOOST_INCLUDE_DIR})

add_library(bc_server STATIC server.cpp session.cpp)

target_include_directories(bc_server PUBLIC ${BOOST_INCLUDE_DIR})

find_library(
        BOOST_SERIALIZATION
        NAMES boost_serialization
        PATHS ${BOOST_LIBRARY_DIR}
)

find_library(
        BOOST_SYSTEM
        NAMES boost_system
        PATHS ${BOOST_LIBRARY_DIR}
)

target_link_libraries(bc_server PUBLIC bc_logger ${BOOST_SERIALIZATION} ${BOOST_SYSTEM})

if(DEFINED COMPILE_OPTIONS)
        target_compile_options(bc_server PUBLIC ${COMPILE_OPTIONS})
        target_compile_options(bc_logger PUBLIC ${COMPILE_OPTIONS})
endif()
