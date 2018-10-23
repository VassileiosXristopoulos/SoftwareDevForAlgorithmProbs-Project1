//
// Created by vassilis on 18/10/2018.
//

#include <cmath>
#include <algorithm>
#include <bitset>
#include <regex>
#include "../header/ComputationMethods.h"

int ComputationMethods::my_mod(int x, int y) {
    return (x % y + y) % y;
}
double ComputationMethods::EucledianDistance(vector<int> x, vector<int> y) {
    double distance=0;
    for (unsigned int j = 0; j < x.size(); j++) {
        distance += pow(x[j] - y[j], 2);
    }
    return sqrt(distance);
}

int ComputationMethods::intVectortoInteger(vector<int> table) {
    int retval = 0;
    int i =0;
    std::reverse(table.begin(),table.end());
    for (auto it = table.begin() ; it != table.end(); it++,i++){
        if(*it){
            retval |= 1<<i;
        }
    }
    return retval;
}

vector<int> ComputationMethods::intToIntVector(int number, int d) {
    vector<int> ret = vector<int>(d);
    for ( int i = 0; i < d; i++) {
        ret[d - 1 - i] = (1 << i & number) != 0;
    }
    return ret;
}

unsigned long ComputationMethods::upper_power_of_two(unsigned long v){
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

void ComputationMethods::getHammingCloseVectors( int changesLeft, vector<int>& str, const int i,
        vector<vector<int>>&res
) {
    if (changesLeft == 0) {
        //print(str);
        res.push_back(str);
        return;
    }
    if (i < 0) return;
    // flip current bit
    str[i] ^= 1;
    getHammingCloseVectors(changesLeft-1,str, i-1,res);
    // or don't flip it (flip it again to undo)
    str[i] ^= 1;
    getHammingCloseVectors(changesLeft,str, i-1,res);
}

double ComputationMethods::cosineDistance(vector<int> &x, vector<int> &y) {
    double sum=0,partial_sumX=0,partial_sumY=0;

    for(unsigned int i=0;i<x.size();i++){
        sum+=x[i]*y[i];
        partial_sumX+=pow(x[i],2);
        partial_sumY+=pow(y[i],2);
    }
    partial_sumX=sqrt(partial_sumX);
    partial_sumY=sqrt(partial_sumY);
    return 1 - sum/(partial_sumX*partial_sumY);
}

vector<string> ComputationMethods::Split(string &line) {
    vector<string> element;
    size_t pos = line.find(' ');
    size_t startPos = 0;
    while (pos != string::npos) {
        element.push_back(line.substr(startPos, pos - startPos));
        startPos = pos + 1;
        pos = line.find(' ', startPos);
    }
    element.push_back(line.substr(startPos, pos - startPos));

    return element;
}
