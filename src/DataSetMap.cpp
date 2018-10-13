//
// Created by vassilis on 13/10/2018.
//

#include "../header/DataSetMap.h"

    DataSetMap::DataSetMap(){}
    DataSetMap::~DataSetMap(){}


void DataSetMap::Insert(Item & item) {
    DataSetMap::Map.insert(pair< string,vector<int> >(item.getName(),item.getContent()));
}

vector<int> *DataSetMap::getElement(string name) {
    return &Map.find(name)->second;
}








