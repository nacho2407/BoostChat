add_executable(BoostChat-server main.cpp)

target_include_directories(BoostChat-server PUBLIC ${CMAKE_SOURCE_DIR}/server/lib ${BOOST_INCLUDE_DIR})

target_link_libraries(BoostChat-server PUBLIC bc_server)

if(DEFINED COMPILE_OPTIONS)
        target_compile_options(BoostChat-server PUBLIC ${COMPILE_OPTIONS})
endif()

install(
        TARGETS BoostChat-server
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/server
)
