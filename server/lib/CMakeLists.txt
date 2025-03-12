add_library(logger SHARED logger.cpp)
add_library(message SHARED message.cpp)
add_library(server SHARED server.cpp)
add_library(session SHARED session.cpp)

find_package(boost-asio REQUIRED)
find_package(boost-serialization REQUIRED)
find_package(boost-system REQUIRED)

target_link_libraries(logger PUBLIC boost-asio)
target_link_libraries(message PUBLIC boost-serialization)
target_link_libraries(server PUBLIC message session boost-asio logger boost-system)
target_link_libraries(session PUBLIC message server boost-asio logger boost-serialization boost-system)
