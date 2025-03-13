add_executable(BoostChat_server main.cpp)

target_include_directories(BoostChat_server PUBLIC ${CMAKE_SOURCE_DIR}/server/lib)

find_package(boost_asio REQUIRED)
target_link_libraries(BoostChat_server PUBLIC bc_server Boost::asio)
