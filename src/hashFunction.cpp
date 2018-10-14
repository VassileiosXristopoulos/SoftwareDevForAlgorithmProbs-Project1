//
// Created by vassilis on 14/10/2018.
//
#include <random>
#include <vector>
#include "../header/hashFunction.h"
extern int d;
hashFunction::hashFunction() {

    if(d<=0){
        cout << "d must be positive while constructing hashFunction" << endl;
        exit(0);
    }
    default_random_engine generator;
    normal_distribution<float> distribution(0.0,1.0);
    v = new float[d];
    for(int i=0; i<d ; i++){
        v[i] = distribution(generator);
    }
    float random = ((float) rand()) / (float) RAND_MAX;
    t = 4 + random * 4; // 4 - 0 // TODO: check for errors, range is [0,4]

}

hashFunction::~hashFunction() {

}

int hashFunction::hash(Item* item) {
    vector<int>p_item = item->getContent();
    float sum=t;
    for(int i=0; i<p_item.size() ;i++){
        sum += ( (float) p_item[i] )*v[i];
    }
    return abs((int)floor(sum/((float)4))); // TODO: declare w
}
