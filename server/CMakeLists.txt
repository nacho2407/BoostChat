set(BOOST_CHAT_SERVER_INSTALL ${BOOST_CHAT_INSTALL}/server)

set(BOOST_LIBS_INCLUDE ${BOOST_LIBS}/include)

find_library(BOOST_SYSTEM boost_system PATHS ${BOOST_LIBS}/lib)
find_library(BOOST_SERIALIZATION boost_serialization PATHS ${BOOST_LIBS}/lib)

set(CMAKE_INSTALL_RPATH "$ORIGIN/lib")

add_executable(boost-chat-server logger.cpp main.cpp server.cpp session.cpp)

target_include_directories(boost-chat-server PUBLIC ${BOOST_LIBS_INCLUDE})
target_link_libraries(boost-chat-server PUBLIC ${BOOST_SYSTEM} ${BOOST_SERIALIZATION})

install(
        TARGETS boost-chat-server
        RUNTIME DESTINATION ${BOOST_CHAT_SERVER_INSTALL}
)

# TODO

# (상수 이름 신경쓰기)

# 1. shared 연결하기

# 2. boost libraries install하기

# 3. 순서 조정하기
