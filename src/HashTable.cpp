//
// Created by vassilis on 14/10/2018.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "../header/HashTable.h"
#include "../header/Item.h"
#include "../header/HashNode.h"
#include "../header/ComputationMethods.h"
using namespace std;
extern int r,L;
HashTable::HashTable(int id,int k, int size,string mode) { //TODO: implement hash table fundamental functionality
    uid = id;
    this->mode = mode;
    TableSize = size;
    Table = vector<vector<HashNode*>>(TableSize);
    H_vector= new hashFunction*[k];
    cosine_vector = new cosineHashfunction*[k];
    for( int a=0; a<k; a++){
       r_vector.push_back(rand()%10+1);
       H_vector[a] = new hashFunction();
       cosine_vector[a] = new cosineHashfunction();
    }
}


HashTable::~HashTable() { //TODO: implement destructor

}
void HashTable::add(Item* item,string mode){
    if(mode.compare("eucledian")==0){
        euclAdd(item);
    }
    else if(mode.compare("cosine")==0){
        cosAdd(item);
    }
}
void HashTable::euclAdd(Item* item) {
    int key = Euclhash(item);
    Table[key].push_back(new HashNode(item,computeGVector(item)));
}
void HashTable::cosAdd(Item *item) {
    int key = cosineHash(item);
    Table[key].push_back(new HashNode(item,computeCosGvector(item)));
}
vector<pair<Item*,double>>  HashTable::findNCloserNeighbrs(Item *item, string mode){
    if(mode.compare("eucledian")==0){
        return euclFindNCloserNeighbrs(item);
    }
    else if(mode.compare("cosine")==0){
        return cosFindNCloserNeighbrs(item);
    }
}

vector<pair<Item *, double>> HashTable::euclFindNCloserNeighbrs(Item *item) {
    int bucket = Euclhash(item);
    vector<int>item_gVector=computeGVector(item);
    item->setGVector(item_gVector);
    return getNCloserNeighbors(item,bucket);

}

vector<pair<Item *, double>> HashTable::cosFindNCloserNeighbrs(Item *item) {
    int key=cosineHash(item);
    vector<int>item_gVector=computeCosGvector(item);
    item->setGVector(item_gVector);
    return getNCloserNeighbors(item,key);
}

pair<Item*,double>  HashTable::findCloserNeighbor(Item *item, string mode){
    if(mode.compare("eucledian")==0){
        return eucledianCloser(item);
    }
    else if(mode.compare("cosine")==0){
        return cosineCloser(item);
    }
}

 pair<Item*,double>  HashTable::cosineCloser(Item *item){
    int key=cosineHash(item);
    vector<int>item_gVector=computeCosGvector(item);
    item->setGVector(item_gVector);
    return findCLoserNeighbor(item,key);

}

 pair<Item*,double> HashTable::eucledianCloser(Item *item) {
    int bucket = Euclhash(item);
    vector<int>item_gVector=computeGVector(item);
    item->setGVector(item_gVector);
    return findCLoserNeighbor(item,bucket);

}

int HashTable::cosineHash(Item* item) {
    vector<int> table = computeCosGvector(item);
    std::reverse(table.begin(),table.end());
    return ComputationMethods::intVectortoInteger(table);

}
int HashTable::Euclhash(Item *item) {
    int sum = 0;
    int M = (int)pow(2.0,32.0) -5;
    vector<int>h_i=computeGVector(item);
    for( int i=0; i< r_vector.size() ; i++){
       sum += ComputationMethods::my_mod(((int)r_vector[i])*h_i[i],M);
    }

    return ComputationMethods::my_mod(sum,TableSize);
}



vector< pair<Item*,double> > HashTable::getNCloserNeighbors(Item *item,int bucket){
    vector< pair<Item*,double> >ret;
    for(int i=0; i<Table[bucket].size(); i++) {
        bool match = true;

        for (int j = 0; j < item->getGVector().size(); j++) {
            if (item->getGVector()[j] != Table[bucket][i]->getGvector()[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            Item * datasetItem = Table[bucket][i]->getItem();

            double distance = computeDistance(item->getContent(), Table[bucket][i]->getItem()
                    ->getContent());
            if (item->getName().compare(datasetItem->getName()) != 0) {
                if (distance < r ) {
                    pair<Item *, double> myPair = make_pair(datasetItem, distance);
                    ret.push_back(myPair);

                }
            }
        }

    }
    return ret;
}

pair<Item*,double> HashTable::findCLoserNeighbor(Item *item,int bucket){
    vector< pair<Item*,double> >ret;
    pair<Item*,double>min_pair(NULL,-1);
    int retrieved=0;
    for(int i=0; i<Table[bucket].size(); i++) {
        bool match = true;
        if(retrieved == 2*L) return min_pair;
        for (int j = 0; j < item->getGVector().size(); j++) {
            if (item->getGVector()[j] != Table[bucket][i]->getGvector()[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            Item *datasetItem = Table[bucket][i]->getItem();

            double distance = computeDistance(item->getContent(), Table[bucket][i]->getItem()
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


vector<int> HashTable::computeCosGvector(Item*item){
    vector<int>ret=vector<int>(k);
    for(int i=0; i<k ;i++){
        ret[i] = cosine_vector[i]->hash(item);
    }
    return ret;

}
vector<int> HashTable::computeGVector(Item* item){
    vector<int> h_i;
    for( int i=0; i< item->getGVector().size() ; i++) {
        h_i.push_back(H_vector[i]->hash(item));
    }
    return h_i;
}

double HashTable::computeDistance(vector<int> &x, vector<int> &y) {
    if(mode.compare("eucledian")==0){
        return ComputationMethods::EucledianDistance(x,y);
    }
    else if(mode.compare("cosine")==0){
        return ComputationMethods::cosineDistance(x,y);
    }
}




