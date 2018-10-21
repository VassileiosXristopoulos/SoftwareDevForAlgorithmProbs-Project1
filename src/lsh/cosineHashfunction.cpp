//
// Created by vassilis on 18/10/2018.
//

#include <random>
#include "../../header/lsh/cosineHashfunction.h"
extern int d;
extern default_random_engine generator;
extern normal_distribution<float> distribution;
cosineHashfunction::cosineHashfunction() {
    if(d<=0){
        cout << "d must be positive while constructing cosineHashFunction" << endl;
        exit(0);
    }
    v = new float[d];
    for(int i=0; i<d ; i++){
        v[i] = distribution(generator);
    }
}

cosineHashfunction::~cosineHashfunction() {

}

int cosineHashfunction::hash(Item *item) {
    vector<int>p_item = item->getContent();
    float sum=0;
    for(int i=0;i<p_item.size();i++){
        sum += p_item[i]*v[i];
    }
    return sum>=0;
}
