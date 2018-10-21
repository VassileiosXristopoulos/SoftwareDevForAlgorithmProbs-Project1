//
// Created by vassilis on 14/10/2018.
//
#include <random>
#include <vector>
#include "../../header/lsh/hashFunction.h"
extern int d;
extern default_random_engine generator;
extern normal_distribution<float> distribution;
hashFunction::hashFunction() {
    if(d<=0){
        cout << "d must be positive while constructing hashFunction" << endl;
        exit(0);
    }

    v = new float[d];
    for(int i=0; i<d ; i++){
        v[i] = distribution(generator);
    }

    t = static_cast<float>(4.0 * ((float)rand() / RAND_MAX));
    if(t<0 || t>4){
        cout << "t == " << t <<endl;
        exit(0);
    }
}

hashFunction::~hashFunction() = default;

int hashFunction::hash(Item* item) {
    vector<int>p_item = item->getContent();
    float sum=t;
    for(int i=0; i<p_item.size() ;i++){
        sum += ( (float) p_item[i] )*v[i];
    }
    auto ret =(int)(sum/100);

    return ret; // TODO: declare w
}

