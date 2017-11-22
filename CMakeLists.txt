cmake_minimum_required(VERSION 3.0)

project(things)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(Lua 5.2 REQUIRED)
find_package(SFML 2 REQUIRED main network audio graphics window system)

set(COMMON_LIBRARIES
    ${LUA_LIBRARIES}
    ${SFML_LIBRARIES}
    )

add_subdirectory(src)
add_subdirectory(externals/googletest)
add_subdirectory(test)