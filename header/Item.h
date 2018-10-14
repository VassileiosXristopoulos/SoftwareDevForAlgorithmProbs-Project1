//
// Created by vassilis on 13/10/2018.
//

#ifndef TEST_ITEM_H
#define TEST_ITEM_H
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
class Item {
private:
    string name;
    vector<int>content;
    int *g_vector;
public:
    Item(vector<string>&element);
    ~Item();
    vector<int>& getContent();
    string getName();
    void setGVector(vector<int>& h_i);
};


#endif //TEST_ITEM_H
