add_library(bc_logger STATIC logger.cpp)
add_library(bc_server STATIC server.cpp session.cpp)

find_package(Boost COMPONENTS serialization system)

if(Boost_FOUND)
        target_include_directories(bc_logger PUBLIC ${Boost_INCLUDE_DIRS})
        target_include_directories(bc_server PUBLIC ${Boost_INCLUDE_DIRS})
        target_link_libraries(bc_server PUBLIC bc_logger Boost::serialization Boost::system)
else()
        message(WARNING "The Boost package could not be found. Set the path through BOOST_ROOT.")

        target_include_directories(bc_logger PUBLIC ${BOOST_ROOT})
        target_include_directories(bc_server PUBLIC ${BOOST_ROOT})

        find_library(
                BOOST_SERIALIZATION
                NAMES boost_serialization
                PATHS ${BOOST_ROOT}/stage/lib
        )

        find_library(
                BOOST_SYSTEM
                NAMES boost_system
                PATHS ${BOOST_ROOT}/stage/lib
        )

        target_link_libraries(bc_server PUBLIC bc_logger ${BOOST_SERIALIZATION} ${BOOST_SYSTEM})

        install(
                FILES ${BOOST_SERIALIZATION} ${BOOST_SYSTEM}
                PERMISSIONS OWNER_WRITE OWNER_READ
                DESTINATION ${CMAKE_SOURCE_DIR}/bin
        )
endif()

install(
        TARGETS bc_logger bc_server
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/bin
        ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib
)
