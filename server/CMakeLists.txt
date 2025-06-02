set(BOOST_CHAT_SERVER_INSTALL_PATH ${BOOST_CHAT_INSTALL_PATH}/server)

set(BOOST_INCLUDE_DIR ${BOOST_DIR}/include)

find_library(BOOST_SYSTEM_LIB boost_system PATHS ${BOOST_DIR}/lib)
find_library(BOOST_SERIALIZATION_LIB boost_serialization PATHS ${BOOST_DIR}/lib)

set(CMAKE_INSTALL_RPATH "$ORIGIN/lib")

###

add_executable(boost-chat-server logger.cpp main.cpp server.cpp session.cpp)

target_include_directories(boost-chat-server PUBLIC ${BOOST_INCLUDE_DIR})
target_link_libraries(boost-chat-server PUBLIC BOOST_SYSTEM_LIB BOOST_SERIALIZATION_LIB)

# 요기 아래부터 재작성(위의 것도 순서 조정 필요)

if(DEFINED BC_COMPILE_OPTIONS)
        target_compile_options(BoostChat-server PRIVATE ${BC_COMPILE_OPTIONS})
endif()

install(
        TARGETS BoostChat-server
        RUNTIME DESTINATION ${BC_SERVER_INSTALL_PATH}
)

###

add_library(bc_logger STATIC logger.cpp)

target_include_directories(bc_logger PUBLIC ${Boost_INCLUDE_DIR})

add_library(bc_server STATIC server.cpp session.cpp)

target_include_directories(bc_server PUBLIC ${Boost_INCLUDE_DIR})

target_link_libraries(bc_server PUBLIC bc_logger Boost::serialization Boost::system)

if(DEFINED BC_COMPILE_OPTIONS)
        target_compile_options(bc_server PUBLIC ${BC_COMPILE_OPTIONS})
        target_compile_options(bc_logger PUBLIC ${BC_COMPILE_OPTIONS})
endif()

