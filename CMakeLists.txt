cmake_minimum_required(VERSION 3.5)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 ")

set(SOURCE_FILES "src/main.cpp"
        "src/DataSetMap.cpp"
        "src/Item.cpp")

add_executable(test ${SOURCE_FILES})
