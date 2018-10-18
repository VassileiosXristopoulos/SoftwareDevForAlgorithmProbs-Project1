//
// Created by vassilis on 13/10/2018.
//

#include "../header/DataSetMap.h"
#include "../header/ComputationMethods.h"

DataSetMap::DataSetMap(){}
    DataSetMap::~DataSetMap(){}


void DataSetMap::append(Item * item) {
    Map.push_back(item);
}



double DataSetMap::TrueDistance(Item *item) {
    double min=-1;
    for( int i=0; i<Map.size(); i++ ){
        double dist = ComputationMethods::EucledianDistance(item->getContent(),Map[i]->getContent());
        if(min==-1 || dist<min)
            min = dist;
    }
    return min;
}

int DataSetMap::size(){
    return Map.size();
}

Item *DataSetMap::at(int index) {
    return Map[index];
}






