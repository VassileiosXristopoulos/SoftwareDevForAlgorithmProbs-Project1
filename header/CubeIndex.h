//
// Created by vassilis on 20/10/2018.
//

#ifndef TEST_CUBEINDEX_H
#define TEST_CUBEINDEX_H

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
class CubeIndex {
private:
    vector<int>index;
public:
    explicit CubeIndex(vector<int>index);
    ~CubeIndex();
    vector<int> content();

};


#endif //TEST_CUBEINDEX_H
