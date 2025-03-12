add_executable(BoostChat_server main.cpp)

target_include_directories(BoostChat_server PUBLIC ${CMAKE_SOURCE_DIR}/src/server/lib)

find_package(boost-asio REQUIRED)
target_link_libraries(BoostChat_server PUBLIC server boost-asio)
