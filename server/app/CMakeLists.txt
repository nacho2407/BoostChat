add_executable(BoostChat-server main.cpp)

target_include_directories(BoostChat-server PUBLIC ${Boost_INCLUDE_DIR})

target_link_libraries(BoostChat-server PUBLIC bc_server)

if(DEFINED BC_COMPILE_OPTIONS)
        target_compile_options(BoostChat-server PRIVATE ${BC_COMPILE_OPTIONS})
endif()

install(
        TARGETS BoostChat-server
        RUNTIME DESTINATION ${BC_SERVER_INSTALL_PATH}
)
