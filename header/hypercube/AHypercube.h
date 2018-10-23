//
// Created by vassilis on 21/10/2018.
//

#ifndef CUBE_AHYPERCUBE_H
#define CUBE_AHYPERCUBE_H


#include "../lsh/cosineHashfunction.h"
#include "BinaryMap.h"
#include "CubeEdge.h"

class AHypercube {
protected:
    BinaryMap binaryMap;
    cosineHashfunction **cosine_vector;
    vector<CubeEdge*>edges;
public:
    explicit AHypercube(int d);
    ~AHypercube();
    virtual  vector<int> getBitVector(Item* item) = 0;
    vector<CubeEdge*> getHamingCLose(int hammingDist,CubeEdge* edge);
    void add(Item* item);
    virtual double computeDistance(vector<int>&x,vector<int>&y) = 0;
    pair<string,double> findCloser(Item *item,int max,int probes);
    vector<string> findRCloser(Item *item,int max,int probes,int radius);
};


#endif //CUBE_AHYPERCUBE_H
