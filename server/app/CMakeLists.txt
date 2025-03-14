add_executable(BoostChat_server main.cpp)

target_include_directories(BoostChat_server PUBLIC ${CMAKE_SOURCE_DIR}/server/lib ${BOOST_INCLUDE_DIR})

target_link_libraries(BoostChat_server PUBLIC bc_server)
