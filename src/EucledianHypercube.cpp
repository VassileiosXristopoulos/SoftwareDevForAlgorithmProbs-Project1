//
// Created by vassilis on 21/10/2018.
//

#include <cmath>
#include "../header/EucledianHypercube.h"
#include "../header/ComputationMethods.h"

EucledianHypercube::EucledianHypercube(int d) : AHypercube(d) {
        for( int i = 0 ;i< d ; i++){
            Hi.push_back(new hashFunction());
        }
}

EucledianHypercube::~EucledianHypercube() {

}

vector<int> EucledianHypercube::getBitVector(Item *item) {
    int dimensions = (int)Hi.size();
    // we want the size of the vector to be power of 2, so as to get
    //  the right number off the conversion from vector to int
    int nextPowof2dimensions = static_cast<int>(ComputationMethods::upper_power_of_two(dimensions));
    vector<int> bitVector((unsigned long)(nextPowof2dimensions));
    // std::reverse(bitVector.begin(),bitVector.end());
    for(int i=0; i< dimensions ; i++){
        int key = Hi[i]->hash(item);
        if(binaryMap.inMap(key)){
            bitVector[i] = binaryMap.get(key);
        }
        else{
            char val = static_cast<char>(rand() % 2);
            binaryMap.add(key,val);
            bitVector[i] = val;
        }
    }
    // std::reverse(bitVector.begin(),bitVector.end());
    return  bitVector;
}

double EucledianHypercube::computeDistance(vector<int> &x, vector<int> &y) {
    ComputationMethods::EucledianDistance(x,y);
}
