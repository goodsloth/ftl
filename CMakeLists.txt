cmake_minimum_required(VERSION 3.16)
project(ftl)

set(CMAKE_CXX_STANDARD 17)

add_library(ftl INTERFACE)
target_include_directories(ftl INTERFACE include/)

add_executable(ftl-test ftl.cc)
target_link_libraries(ftl-test ftl)
