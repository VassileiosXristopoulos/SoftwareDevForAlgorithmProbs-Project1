//
// Created by vassilis on 21/10/2018.
//

#ifndef CUBE_COSINEHASHTABLE_H
#define CUBE_COSINEHASHTABLE_H


#include "AHashTable.h"
#include "cosineHashfunction.h"

class CosineHashTable : public AHashTable{
private:
    vector<cosineHashfunction *>cosine_vector;
    int k;
public:
    CosineHashTable(int size,int k);
    ~CosineHashTable();
    vector<int> computeGVector(Item* item) override;
    int hash(Item*item) override;
    void add(Item* item) override;
    vector<string>  findNcloserNeighbors(Item *item) override;
    pair<Item *, double>  findCloserNeighbor(Item *item) override;

};


#endif //CUBE_COSINEHASHTABLE_H
