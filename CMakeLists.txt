cmake_minimum_required(VERSION 3.0)

project(things)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_subdirectory(src)
add_subdirectory(externals/googletest)
add_subdirectory(test)