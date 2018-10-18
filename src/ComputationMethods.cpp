//
// Created by vassilis on 18/10/2018.
//

#include <cmath>
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