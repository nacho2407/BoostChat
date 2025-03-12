add_executable(BoostChat_server main.cpp)

target_include_directories(BoostChat_server PUBLIC ${CMAKE_SOURCE_DIR}/server/lib)

find_package(Boost REQUIRED COMPONENTS asio)
target_link_libraries(BoostChat_server PUBLIC server Boost::asio)
