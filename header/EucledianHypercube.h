//
// Created by vassilis on 21/10/2018.
//

#ifndef CUBE_EUCLEDIANHYPERCUBE_H
#define CUBE_EUCLEDIANHYPERCUBE_H


#include "AHypercube.h"
#include "hashFunction.h"

class EucledianHypercube : public AHypercube{
private:
    vector<hashFunction*>Hi;
public:
    EucledianHypercube(int d);
    ~EucledianHypercube();
    vector<int> getBitVector(Item* item) override;
    double computeDistance(vector<int>&x,vector<int>&y) override;
};


#endif //CUBE_EUCLEDIANHYPERCUBE_H
