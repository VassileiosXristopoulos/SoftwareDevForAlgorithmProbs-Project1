//
// Created by vassilis on 20/10/2018.
//

#include <cmath>
#include <algorithm>
#include "../../header/hypercube/CosineHypercube.h"
#include "../../header/ComputationMethods.h"
#include "../../header/lsh/cosineHashfunction.h"
#include "../../header/hypercube/AHypercube.h"

CosineHypercube::CosineHypercube(int d) : AHypercube(d) {
    cosine_vector = vector<cosineHashfunction *>(d);
    for(int i=0; i<d ;i++){
        cosine_vector[i] = new cosineHashfunction();
    }
}

CosineHypercube::~CosineHypercube() = default;

vector<int> CosineHypercube::getBitVector(Item*item){
    int dimensions = (int)cosine_vector.size();
    // we want the size of the vector to be power of 2, so as to get
    //  the right number off the conversion from vector to int
    int nextPowof2dimensions = static_cast<int>(ComputationMethods::upper_power_of_two(dimensions));
    vector<int>ret(nextPowof2dimensions);
    for(int i=0; i<dimensions ;i++){
        ret[i] = cosine_vector[i]->hash(item);
    }
    return ret;

}


double CosineHypercube::computeDistance(vector<int>&x,vector<int>&y) {
    return ComputationMethods::cosineDistance(x,y);
}





