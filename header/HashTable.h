//
// Created by vassilis on 14/10/2018.
//

#ifndef TEST_HASHTABLE_H
#define TEST_HASHTABLE_H

#include <vector>
#include "Item.h"
#include "hashFunction.h"
#include "HashNode.h"

using namespace std;

class HashTable {
private:
    int uid;
    int TableSize;
    vector< vector<HashNode*> >Table;
    hashFunction **H_vector;
    vector<int> r_vector;
    int hash(Item* item);
    vector<int> computeGVector(Item* item);
public:
    HashTable(int id,int k,int size);
    ~HashTable();
    void add(Item* item);
    void print();
    vector< pair<Item*,double> > findNCloser(Item *item);

};


#endif //TEST_HASHTABLE_H
