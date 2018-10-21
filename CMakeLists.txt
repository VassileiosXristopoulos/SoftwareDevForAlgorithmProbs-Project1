cmake_minimum_required(VERSION 3.5)
project(LSH)
project(CUBE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(LSH "src/lsh.cpp"
        "src/DataSetMap.cpp"
        "src/Item.cpp"
        "src/EucledianHashTable.cpp"
        "src/hashFunction.cpp"
        "src/HashNode.cpp"
        "src/ComputationMethods.cpp"
        "src/cosineHashfunction.cpp"
        "src/AHashTable.cpp"
        "src/CosineHashTable.cpp")

set(CUBE "src/cube.cpp"
        "src/DataSetMap.cpp"
        "src/Item.cpp"
        "src/hashFunction.cpp"
        "src/ComputationMethods.cpp"
        "src/CosineHypercube.cpp"
        "src/CubeEdge.cpp"
        "src/CubeIndex.cpp"
        "src/BinaryMap.cpp"
        "src/cosineHashfunction.cpp"
        "src/AHypercube.cpp"
        "src/EucledianHypercube.cpp")

add_executable(LSH ${LSH})
add_executable(CUBE ${CUBE})
