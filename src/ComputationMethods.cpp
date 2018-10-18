//
// Created by vassilis on 18/10/2018.
//

#include <cmath>
#include <algorithm>
#include "../header/ComputationMethods.h"


int ComputationMethods::my_mod(int x, int y) {
    return (x % y + y) % y;
}
double ComputationMethods::EucledianDistance(vector<int> x, vector<int> y) {
    double distance=0;
    for (int j = 0; j < x.size(); j++) {
        distance += pow(x[j] - y[j], 2);
    }
    return sqrt(distance);
}

int ComputationMethods::intVectortoInteger(vector<int> table) {
    int retval = 0;
    int i =0;
    vector<int>starting = table;
    std::reverse(table.begin(),table.end());
    for (vector<int>::iterator it = table.begin() ; it != table.end(); it++,i++){
        if(*it.base()==1 ){
            retval |= 1<<i;
        }
    }
    return retval;
}
