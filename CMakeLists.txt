cmake_minimum_required(VERSION 3.5)
project(LSH)
project(CUBE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(LSH "src/lsh/lsh.cpp"
        "src/DataSetMap.cpp"
        "src/Item.cpp"
        "src/lsh/EucledianHashTable.cpp"
        "src/lsh/hashFunction.cpp"
        "src/lsh/HashNode.cpp"
        "src/Util.cpp"
        "src/lsh/cosineHashfunction.cpp"
        "src/lsh/AHashTable.cpp"
        "src/lsh/CosineHashTable.cpp")

set(CUBE "src/hypercube/cube.cpp"
        "src/DataSetMap.cpp"
        "src/Item.cpp"
        "src/lsh/hashFunction.cpp"
        "src/Util.cpp"
        "src/hypercube/CosineHypercube.cpp"
        "src/hypercube/CubeEdge.cpp"
        "src/hypercube/BinaryMap.cpp"
        "src/lsh/cosineHashfunction.cpp"
        "src/hypercube/AHypercube.cpp"
        "src/hypercube/EucledianHypercube.cpp")

add_executable(LSH ${LSH})
add_executable(CUBE ${CUBE})
