//
// Created by vassilis on 20/10/2018.
//

#ifndef TEST_HYPERCUBE_H
#define TEST_HYPERCUBE_H


#include <map>
#include "../lsh/hashFunction.h"
#include "BinaryMap.h"
#include "../lsh/cosineHashfunction.h"
#include "AHypercube.h"

class CosineHypercube : public AHypercube {
private:
    vector<cosineHashfunction *>cosine_vector;


public:
    explicit CosineHypercube(int d);
    ~CosineHypercube();
    vector<int> getBitVector(Item *item) override;
    double computeDistance(vector<int>&x,vector<int>&y) override;

};


#endif //TEST_HYPERCUBE_H
