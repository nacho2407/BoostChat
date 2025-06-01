add_library(bc_logger STATIC logger.cpp)

target_include_directories(bc_logger PUBLIC ${Boost_INCLUDE_DIR})

add_library(bc_server STATIC server.cpp session.cpp)

target_include_directories(bc_server PUBLIC ${Boost_INCLUDE_DIR})

target_link_libraries(bc_server PUBLIC bc_logger Boost::serialization Boost::system)

if(DEFINED BC_COMPILE_OPTIONS)
        target_compile_options(bc_server PUBLIC ${BC_COMPILE_OPTIONS})
        target_compile_options(bc_logger PUBLIC ${BC_COMPILE_OPTIONS})
endif()
