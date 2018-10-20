//
// Created by vassilis on 20/10/2018.
//

#ifndef TEST_CUBEENTRY_H
#define TEST_CUBEENTRY_H


#include "CubeIndex.h"
#include "Item.h"

class CubeEdge {
private:
    CubeIndex* index;
    vector<Item*>elements;
public:
    CubeEdge(vector<int>index);
    ~CubeEdge();
    void add(Item* item);
    vector<Item*> Elements();
    CubeIndex* getIndex();
};


#endif //TEST_CUBEENTRY_H
