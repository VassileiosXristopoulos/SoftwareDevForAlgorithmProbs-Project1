//
// Created by vassilis on 14/10/2018.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../header/HashTable.h"
using namespace std;
HashTable::HashTable(int k) { //TODO: implement hash table fundamental functionality


    H_vector= new hashFunction*[k];
    for( int i=0; i<k; i++){
       r_vector.push_back(rand());
       H_vector[i] = new hashFunction();
    }
}

HashTable::~HashTable() {

}

int HashTable::hash(Item item) {
    int sum = 0, M = 2^32 -5;
    vector<int>h_i(r_vector.size());
    for( int i=0; i< r_vector.size() ; i++){
        h_i[i] = H_vector[i]->hash(item);
        sum += h_i[i]*r_vector[i];
    }
    item.setGVector(h_i);
    return (sum % M) % TableSize;
}
