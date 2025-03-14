add_executable(BoostChat_server main.cpp)

find_package(Boost COMPONENTS asio)

if(Boost_FOUND)
        target_link_libraries(BoostChat_server PUBLIC Boost::asio)
else()
        message(WARNING "The Boost package could not be found. Set the path through BOOST_ROOT.")

        target_include_directories(BoostChat_server PUBLIC ${CMAKE_SOURCE_DIR}/server/lib ${BOOST_ROOT})

        install(
                TARGETS BoostChat_server
                RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
        )
endif()

target_link_libraries(BoostChat_server PUBLIC bc_server)
