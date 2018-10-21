//
// Created by vassilis on 21/10/2018.
//

#include <algorithm>
#include "../../header/lsh/CosineHashTable.h"
#include "../../header/ComputationMethods.h"
extern int r,L;
CosineHashTable::CosineHashTable(int size, int k) : AHashTable(size,k){
    cosine_vector = new cosineHashfunction*[k];
    for( int a=0; a<k; a++){
        cosine_vector[a] = new cosineHashfunction();
    }
}

vector<int> CosineHashTable::computeGVector(Item *item) {
    vector<int>ret=vector<int>(k);
    for(int i=0; i<k ;i++){
        ret[i] = cosine_vector[i]->hash(item);
    }
    return ret;
}

int CosineHashTable::hash(Item *item) {
    vector<int> table = computeGVector(item);
    std::reverse(table.begin(),table.end());
    return ComputationMethods::intVectortoInteger(table);
}

void CosineHashTable::add(Item *item) {
    int key = hash(item);
    Table[key].push_back(new HashNode(item,computeGVector(item)));
}

vector<pair<Item *, double>>  CosineHashTable::findNcloserNeighbors(Item *item) {
    int bucket = hash(item);
    vector<int>item_gVector=computeGVector(item);
    item->setGVector(item_gVector);
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

            double distance = ComputationMethods::cosineDistance(item->getContent(), Table[bucket][i]->getItem()
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

pair<Item *, double> CosineHashTable::findCloserNeighbor(Item *item) {
    int bucket = hash(item);
    vector<int>item_gVector=computeGVector(item);
    item->setGVector(item_gVector);
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

            double distance = ComputationMethods::cosineDistance(item->getContent(), Table[bucket][i]->getItem()
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

