add_library(logger SHARED logger.cpp)
add_library(message SHARED message.cpp)
add_library(server SHARED server.cpp session.cpp)

find_package(Boost REQUIRED COMPONENTS asio serialization system)

target_link_libraries(logger PUBLIC Boost::asio)
target_link_libraries(message PUBLIC Boost::serialization)
target_link_libraries(server PUBLIC message Boost::asio logger Boost::system Boost::serialization)
