cmake_minimum_required(VERSION 3.31)
project(Yocto_AlgoGym)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/googletest)

include_directories(include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/googletest/include)

# 查找所有测试文件
file(GLOB TEST_SOURCES tests/*/*/*.cpp)

add_executable(Yocto_AlgoGym
        include/test_registry.h
        src/main.cpp
        ${TEST_SOURCES}
)

# 链接GoogleTest库
target_link_libraries(Yocto_AlgoGym gtest gtest_main)