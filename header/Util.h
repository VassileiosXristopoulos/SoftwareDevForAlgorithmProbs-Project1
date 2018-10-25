//
// Created by vassilis on 18/10/2018.
//

#ifndef TEST_COMPUTATIONMETHODS_H
#define TEST_COMPUTATIONMETHODS_H


#include "Item.h"

class ComputationMethods {
public:
    static int my_mod(int x, int y);

    static double EucledianDistance(vector<int> x, vector<int> y);

    static int intVectortoInteger(vector<int> table);

    static vector<int> intToIntVector(int number, int d);

    static unsigned long upper_power_of_two(unsigned long v);

    static void getHammingCloseVectors( int changesLeft, std::vector<int>& str, const int i,
            vector<vector<int>>&res );
    static double cosineDistance(vector<int>&x,vector<int>&y);
    static vector<string> Split(string &line);
};

#endif //TEST_COMPUTATIONMETHODS_H
