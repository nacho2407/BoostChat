add_library(bc_logger SHARED logger.cpp)
add_library(bc_server SHARED server.cpp session.cpp)

find_package(boost_asio REQUIRED)
find_package(boost_serialization REQUIRED)
find_package(boost_system REQUIRED)

target_link_libraries(bc_logger PUBLIC Boost::asio)
target_link_libraries(bc_server PUBLIC Boost::serialization Boost::asio bc_logger Boost::system)
