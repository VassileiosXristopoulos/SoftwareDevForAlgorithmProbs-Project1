//
// Created by vassilis on 20/10/2018.
//

#ifndef TEST_HYPERCUBE_H
#define TEST_HYPERCUBE_H


#include <map>
#include "hashFunction.h"
#include "CubeEdge.h"
#include "BinaryMap.h"
#include "cosineHashfunction.h"

class Hypercube {
private:
    string mode;
    vector<hashFunction*>Hi;
    vector<CubeEdge*>edges;
    BinaryMap binaryMap;
    cosineHashfunction **cosine_vector;
    vector<int> getEuclBitVector(Item* item);
    vector<int> computeCosGvector(Item*item);
    vector<CubeEdge*> getHamingCLose(int hammingDist,CubeEdge* edge);
    double computeDistance(vector<int>&x,vector<int>&y);

public:
    Hypercube(int d,string mode);
    ~Hypercube();
    void add(Item *item);
    pair<string,double> findCloser(Item *item,int max,int probes);
    vector<pair<string,double>> findEuclRCloser(Item *item,int max,int probes,int radius);
    vector<int> getBitVector(Item *item);

    };


#endif //TEST_HYPERCUBE_H
