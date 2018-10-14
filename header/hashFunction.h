//
// Created by vassilis on 14/10/2018.
//

#ifndef TEST_HASHFUNCTION_H
#define TEST_HASHFUNCTION_H

#include "Item.h"
class hashFunction {
private:
    float *v;
    float t;
public:
    hashFunction();
    ~hashFunction();
    int hash(Item item);
};


#endif //TEST_HASHFUNCTION_H
