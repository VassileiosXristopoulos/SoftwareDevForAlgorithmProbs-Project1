CC=g++ -std=c++11
CFLAGS=-Wall -g3 
LFLAGS_LSH= -g3 -o lsh
LFLAGS_CUBE= -g3 -o cube
OBJS_LSH=obj/lsh.o obj/DataSetMap.o obj/Item.o obj/EucledianHashTable.o obj/hashFunction.o obj/HashNode.o obj/ComputationMethods.o obj/cosineHashfunction.o obj/AHashTable.o obj/CosineHashTable.o 
OBJS_CUBE=obj/cube.o obj/EucledianHypercube.o obj/CosineHypercube.o obj/CubeEdge.o obj/BinaryMap.o obj/cosineHashfunction.o obj/AHypercube.o obj/ComputationMethods.o obj/Item.o obj/DataSetMap.o obj/hashFunction.o 
MOVE=$(shell mv *.o obj)

all:lsh cube

lsh: $(OBJS_LSH)
	$(CC) $(CFLAGS) $(OBJS_LSH) $(LFLAGS_LSH) $(MOVE)

cube: $(OBJS_CUBE)
	$(CC) $(CFLAGS) $(OBJS_CUBE) $(LFLAGS_CUBE) $(MOVE)

obj/lsh.o: src/lsh/lsh.cpp
	$(CC) $(CFLAGS) -c src/lsh/lsh.cpp 

obj/DataSetMap.o: src/DataSetMap.cpp
	$(CC) $(CFLAGS) -c src/DataSetMap.cpp 

obj/Item.o: src/Item.cpp
	$(CC) $(CFLAGS) -c src/Item.cpp

obj/EucledianHashTable.o: src/lsh/EucledianHashTable.cpp
	$(CC) $(CFLAGS) -c src/lsh/EucledianHashTable.cpp

obj/hashFunction.o: src/lsh/hashFunction.cpp
	$(CC) $(CFLAGS) -c src/lsh/hashFunction.cpp

obj/HashNode.o: src/lsh/HashNode.cpp
	$(CC) $(CFLAGS) -c src/lsh/HashNode.cpp

obj/ComputationMethods.o: src/ComputationMethods.cpp
	$(CC) $(CFLAGS) -c src/ComputationMethods.cpp

obj/cosineHashfunction.o: src/lsh/cosineHashfunction.cpp
	$(CC) $(CFLAGS) -c src/lsh/cosineHashfunction.cpp

obj/AHashTable.o: src/lsh/AHashTable.cpp
	$(CC) $(CFLAGS) -c src/lsh/AHashTable.cpp

obj/CosineHashTable.o: src/lsh/CosineHashTable.cpp
	$(CC) $(CFLAGS) -c src/lsh/CosineHashTable.cpp

obj/cube.o: src/hypercube/cube.cpp
	$(CC) $(CFLAGS) -c src/hypercube/cube.cpp

obj/EucledianHypercube.o: src/hypercube/EucledianHypercube.cpp
	$(CC) $(CFLAGS) -c src/hypercube/EucledianHypercube.cpp

obj/CosineHypercube.o: src/hypercube/CosineHypercube.cpp
	$(CC) $(CFLAGS) -c src/hypercube/CosineHypercube.cpp

obj/CubeEdge.o: src/hypercube/CubeEdge.cpp
	$(CC) $(CFLAGS) -c src/hypercube/CubeEdge.cpp

obj/BinaryMap.o: src/hypercube/BinaryMap.cpp
	$(CC) $(CFLAGS) -c src/hypercube/BinaryMap.cpp

obj/AHypercube.o: src/hypercube/AHypercube.cpp
	$(CC) $(CFLAGS) -c src/hypercube/AHypercube.cpp

clean:
	rm -f lsh $(OBJS_LSH) $(OBJS_CUBE)
