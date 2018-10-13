//
// Created by vassilis on 13/10/2018.
//

#ifndef TEST_DATASETMAP_H
#define TEST_DATASETMAP_H

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;
class DataSetMap {
private:
    map< string, vector<int> > Map;
public:
    DataSetMap();
    ~DataSetMap();
    void Insert( Item & item);
    vector<int>* getElement(string name);

};


#endif
