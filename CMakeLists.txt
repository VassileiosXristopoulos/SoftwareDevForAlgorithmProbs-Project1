cmake_minimum_required(VERSION 3.5)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES "src/main.cpp"
        "src/DataSetMap.cpp"
        "src/Item.cpp"
        "src/HashTable.cpp"
        "src/hashFunction.cpp"
        "src/HashNode.cpp"
        "src/ComputationMethods.cpp"
        "src/cosineHashfunction.cpp")


add_executable(test ${SOURCE_FILES})
