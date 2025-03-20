set(BC_SERVER_INSTALL_PATH "${CMAKE_SOURCE_DIR}/bin/server")

find_package(Boost REQUIRED COMPONENTS serialization system)

if(DEFINED BC_BOOST_SHARED)
        file(GLOB BC_BOOST_SERIALIZATION "${Boost_LIBRARY_DIRS}/*boost_serialization*")
        file(GLOB BC_BOOST_SYSTEM "${Boost_LIBRARY_DIRS}/*boost_system*")

        install(
                FILES ${BC_BOOST_SERIALIZATION} ${BC_BOOST_SYSTEM}
                DESTINATION ${BC_SERVER_INSTALL_PATH}
        )
        
        set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

add_subdirectory(app)
add_subdirectory(lib)
