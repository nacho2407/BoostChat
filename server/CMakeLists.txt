set(BOOST_CHAT_SERVER_INSTALL_PATH ${BOOST_CHAT_INSTALL_PATH}/server)

add_executable(boost-chat-server)

set_target_properties(boost-chat-server PROPERTIES
    INSTALL_RPATH "$ORIGIN;$ORIGIN/lib"
)

target_sources(boost-chat-server
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/logger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/server.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/session.cpp
        ${BOOST_CHAT_SHARED}/src/message.cpp
)

target_include_directories(boost-chat-server
    PRIVATE
        ${BOOST_CHAT_SHARED}/include
        ${EXT_LIBS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(boost-chat-server
    PRIVATE
        ${BOOST_SYSTEM}
        ${BOOST_SERIALIZATION}
)

install(TARGETS boost-chat-server
    RUNTIME DESTINATION ${BOOST_CHAT_SERVER_INSTALL_PATH}
)

file(GLOB BOOST_CHAT_SERVER_DEP_LIBS
    "${EXT_LIBS}/boost/lib/libboost_system.so*"
    "${EXT_LIBS}/boost/lib/libboost_serialization.so*"
)

install(FILES ${BOOST_CHAT_SERVER_DEP_LIBS}
    DESTINATION ${BOOST_CHAT_INSTALL_PATH}/lib
)
