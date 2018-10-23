//
// Created by vassilis on 14/10/2018.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "../../header/lsh/EucledianHashTable.h"
#include "../../header/Item.h"
#include "../../header/lsh/HashNode.h"
#include "../../header/ComputationMethods.h"
using namespace std;
extern int r,L;
EucledianHashTable::EucledianHashTable(int k, int size): AHashTable(size,k) {
    H_vector= new hashFunction*[k];
    for(  int a=0; a<k; a++){
       r_vector.push_back(rand()%10+1);
       H_vector[a] = new hashFunction();
    }
}


EucledianHashTable::~EucledianHashTable() { //TODO: implement destructor

}
void EucledianHashTable::add(Item* item){
    int key = hash(item);
    Table[key].push_back(new HashNode(item,computeGVector(item)));
}




int EucledianHashTable::hash(Item *item) {
    int sum = 0;
    int M = (int)pow(2.0,32.0) -5;
    vector<int>h_i=computeGVector(item);
    for(unsigned  int i=0; i< r_vector.size() ; i++){
       sum += ComputationMethods::my_mod(((int)r_vector[i])*h_i[i],M);
    }

    return ComputationMethods::my_mod(sum,TableSize);
}



vector< string > EucledianHashTable::findNcloserNeighbors(Item *item){
    int bucket = hash(item);
    vector<int>item_gVector=computeGVector(item);
    item->setGVector(item_gVector);
    vector< string >ret;
    for(unsigned int i=0; i<Table[bucket].size(); i++) {
        bool match = true;

        for (unsigned int j = 0; j < item->getGVector().size(); j++) {
            if (item->getGVector()[j] != Table[bucket][i]->getGvector()[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            Item * datasetItem = Table[bucket][i]->getItem();

            double distance = ComputationMethods::EucledianDistance(item->getContent(), Table[bucket][i]->getItem()
                    ->getContent());
            if (item->getName().compare(datasetItem->getName()) != 0) {
                if (distance < r ) {
                    ret.push_back(datasetItem->getName());
                }
            }
        }

    }
    return ret;
}

pair<Item*,double> EucledianHashTable::findCloserNeighbor(Item *item){
    int bucket = hash(item);
    vector<int>item_gVector=computeGVector(item);
    item->setGVector(item_gVector);
    vector< pair<Item*,double> >ret;
    pair<Item*,double>min_pair(NULL,-1);
    int retrieved=0;
    for(unsigned int i=0; i<Table[bucket].size(); i++) {
        bool match = true;
        if(retrieved == 2*L) return min_pair;
        for (unsigned int j = 0; j < item->getGVector().size(); j++) {
            if (item->getGVector()[j] != Table[bucket][i]->getGvector()[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            Item *datasetItem = Table[bucket][i]->getItem();

            double distance = ComputationMethods::EucledianDistance(item->getContent(), Table[bucket][i]->getItem()
                    ->getContent());
            if (item->getName().compare(datasetItem->getName()) != 0) {
                if (min_pair.second == -1 || min_pair.second > distance ) {
                    min_pair.second = distance;
                    min_pair.first = datasetItem;
                    retrieved++;
                }
            }
        }
    }
    return min_pair;

}

vector<int> EucledianHashTable::computeGVector(Item* item){
    vector<int> h_i;
    for(unsigned  int i=0; i< item->getGVector().size() ; i++) {
        h_i.push_back(H_vector[i]->hash(item));
    }
    return h_i;
}





