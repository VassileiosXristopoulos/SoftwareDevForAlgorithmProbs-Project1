//
// Created by vassilis on 14/10/2018.
//

#ifndef TEST_HASHTABLE_H
#define TEST_HASHTABLE_H

#include <vector>
#include "Item.h"
#include "hashFunction.h"
#include "HashNode.h"
#include "cosineHashfunction.h"

using namespace std;

class HashTable {
private:
    int uid;
    int TableSize;
    vector< vector<HashNode*> >Table;
    hashFunction **H_vector;
    cosineHashfunction **cosine_vector;
    vector<int> r_vector;
    int Euclhash(Item* item);
    int cosineHash(Item* item);
    vector<int> computeGVector(Item* item);
    vector< pair<Item*,double> > eucledian(Item *item);
    vector< pair<Item*,double> > cosine(Item *item);
    vector<int> computeCosGvector(Item*item);
    vector< pair<Item*,double> > getCloser(Item *item,int bucket);
    void euclAdd(Item* item);
    void cosAdd(Item* item);
    void print();
    pair< Item*,double > cosineCloser(Item *item);
    pair< Item*,double > eucledianCloser(Item *item);
    pair<Item*,double> findCLoserNeighbor(Item *item,int bucket);
    vector<pair<Item*,double>>  euclFindNCloserNeighbrs(Item *item);
    vector<pair<Item*,double>>  cosFindNCloserNeighbrs(Item *item);
    vector< pair<Item*,double> > getNCloserNeighbors(Item *item,int bucket);
public:
    HashTable(int id,int k,int size);
    ~HashTable();
    void add(Item* item,string mode);
    pair< Item*,double > findCloserNeighbor(Item *item, string mode);
    vector<pair<Item*,double>>  findNCloserNeighbrs(Item *item, string mode);


    };


#endif //TEST_HASHTABLE_H
