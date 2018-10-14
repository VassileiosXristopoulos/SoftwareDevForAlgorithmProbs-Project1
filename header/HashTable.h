//
// Created by vassilis on 14/10/2018.
//

#ifndef TEST_HASHTABLE_H
#define TEST_HASHTABLE_H

#include <vector>
#include "Item.h"
#include "hashFunction.h"

using namespace std;

class HashTable {
private:
    int TableSize;
    hashFunction **H_vector;
    vector<int> r_vector;
public:
    HashTable(int k);
    ~HashTable();
    int hash(Item item);
};


#endif //TEST_HASHTABLE_H
