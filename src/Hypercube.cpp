//
// Created by vassilis on 20/10/2018.
//

#include <cmath>
#include <algorithm>
#include "../header/Hypercube.h"
#include "../header/ComputationMethods.h"
#include "../header/cosineHashfunction.h"
Hypercube::Hypercube(int d,string mode) {
    this->mode = mode;
    cosine_vector = new cosineHashfunction*[k];
    for(int i=0; i<d ;i++){
        Hi.push_back(new hashFunction());
        cosine_vector[i] = new cosineHashfunction();
    }
    for( int i = 0 ;i< pow(2,d) ; i++)
        edges.push_back(new CubeEdge(ComputationMethods::intToIntVector(i,d)));

}

Hypercube::~Hypercube() {

}
vector<int> Hypercube::computeCosGvector(Item*item){
    int dimensions = (int)Hi.size();
    // we want the size of the vector to be power of 2, so as to get
    //  the right number off the conversion from vector to int
    int nextPowof2dimensions = static_cast<int>(ComputationMethods::upper_power_of_two(dimensions));
    vector<int>ret(nextPowof2dimensions);
    for(int i=0; i<dimensions ;i++){
        ret[i] = cosine_vector[i]->hash(item);
    }
    return ret;

}
vector<int> Hypercube::getBitVector(Item *item){
    vector<int>bitVector;
    if(mode.compare("eucledian")==0)
        bitVector = getEuclBitVector(item); //getBitvector returns the right vector
    else if(mode.compare("cosine")==0)
        bitVector = computeCosGvector(item);
    return bitVector;
}
vector<int> Hypercube::getEuclBitVector(Item *item) {
    int dimensions = (int)Hi.size();
    // we want the size of the vector to be power of 2, so as to get
    //  the right number off the conversion from vector to int
    int nextPowof2dimensions = static_cast<int>(ComputationMethods::upper_power_of_two(dimensions));
    vector<int> bitVector((unsigned long)(nextPowof2dimensions));
    // std::reverse(bitVector.begin(),bitVector.end());
    for(int i=0; i< dimensions ; i++){
        int key = Hi[i]->hash(item);
        if(binaryMap.inMap(key)){
            bitVector[i] = binaryMap.get(key);
        }
        else{
            char val = static_cast<char>(rand() % 2);
            binaryMap.add(key,val);
            bitVector[i] = val;
        }
    }
    // std::reverse(bitVector.begin(),bitVector.end());
    return  bitVector;
}

void Hypercube::add(Item *item) {
    vector<int>bitVector = getBitVector(item);
    std::reverse(bitVector.begin(),bitVector.end());//intVectortoInteger computes int with reversed bitVector
    edges[ComputationMethods::intVectortoInteger(bitVector)]->add(item);
}



pair<string,double> Hypercube::findCloser(Item *item,int max,int probes) {
    vector<int>bitVector = getBitVector(item); //getBitvector returns the right vector
    std::reverse(bitVector.begin(),bitVector.end());//intVectortoInteger computes int with reversed bitVector
    CubeEdge * currentEdge = edges[ComputationMethods::intVectortoInteger(bitVector)];
    vector<Item*>elements = currentEdge->Elements();
    pair<string,double>min_item("",-1);
    int elems_checked = 0;
    for(int i=0;i < elements.size() ;i++){
        if(elems_checked++ > max) return min_item;
        double dist = computeDistance(item->getContent(),elements[i]->getContent());
        if(min_item.second<0 || min_item.second>dist){
            min_item.first = elements[i]->getName();
            min_item.second = dist;
        }
    }
    int hamminDist = 1, probes_checked = 0;
    while(1){
        if(probes_checked==probes) break;
        vector<CubeEdge*> hamingClose = getHamingCLose(hamminDist,currentEdge);
        if(hamingClose.size()==0) return min_item; // no other edge available

        for(int i=0 ; i<hamingClose.size(); i++){ //for each close edge

            vector<Item*> items = hamingClose[i]->Elements();
            for(int j=0 ; j<items.size() ; j++){ // for each element of close edge
                if(elems_checked++ > max) return min_item;
                double dist = computeDistance(item->getContent(),items[j]->getContent());
                if(min_item.second<0 || min_item.second>dist){
                    min_item.first = items[j]->getName();
                    min_item.second = dist;
                }
            }

            if(++probes_checked==probes) return min_item;
        }

      hamminDist++;
    }
    return min_item;
}

vector<pair<string,double>> Hypercube::findEuclRCloser(Item *item,int max,int probes,int radius) {
    vector<int>bitVector = getBitVector(item); //getBitvector returns the right vector
    std::reverse(bitVector.begin(),bitVector.end());//intVectortoInteger computes int with reversed bitVector
    CubeEdge * currentEdge = edges[ComputationMethods::intVectortoInteger(bitVector)];
    vector<Item*>elements = currentEdge->Elements();
    vector<pair<string,double>>rNearest;
    int elems_checked = 0;
    for(int i=0;i < elements.size() ;i++){
        if(elems_checked++ > max) return rNearest;
        double dist = computeDistance(item->getContent(),elements[i]->getContent());
        if(dist<radius)
            rNearest.push_back(make_pair(elements[i]->getName(),dist));

    }
    int hamminDist = 1, probes_checked = 0;
    while(1){
        if(probes_checked==probes) break;
        vector<CubeEdge*> hamingClose = getHamingCLose(hamminDist,currentEdge);
        if(hamingClose.size()==0) return rNearest; // no other edge available

        for(int i=0 ; i<hamingClose.size(); i++){ //for each close edge

            vector<Item*> items = hamingClose[i]->Elements();
            for(int j=0 ; j<items.size() ; j++){ // for each element of close edge
                if(elems_checked++ > max) return rNearest;
                double dist = computeDistance(item->getContent(),items[j]->getContent());
                if(dist<radius)
                    rNearest.push_back(make_pair(items[j]->getName(),dist));
            }

            if(++probes_checked==probes) return rNearest;
        }

        hamminDist++;
    }
    return rNearest;
}

vector<CubeEdge *> Hypercube::getHamingCLose(int hammingDist, CubeEdge *edge) {
    vector<int>index = edge->getIndex()->content();
    size_t sizeOfIndex = index.size();
    vector<CubeEdge *> closeEdges;
    vector<vector<int>> indexes; //the indexes are stored correctly, not need to reverse
    ComputationMethods::getHammingCloseVectors(hammingDist,index,sizeOfIndex-1,indexes);
    for(int i=0 ;i<indexes.size() ;i++){
        int upperPowof2 = ComputationMethods::upper_power_of_two(indexes[i].size());
        vector<int>fullSize_vector(upperPowof2);
        /*-------- vector's size is not power of 2, make it ---------*/
        if(indexes[i].size()!= upperPowof2){
            for(int j=0;j<indexes[i].size();j++){
                fullSize_vector[j] = indexes[i][j];
            }

        }
        else
            fullSize_vector = indexes[i];
        /*-----------------------------------------------------------*/
        std::reverse(fullSize_vector.begin(),fullSize_vector.end());//intVectortoInteger computes int with reversed bitVector
        closeEdges.push_back(edges[ComputationMethods::intVectortoInteger(fullSize_vector)]);
        // push back the edge that has the index "fullsize_vector"
    }

    return closeEdges;
}

double Hypercube::computeDistance(vector<int>&x,vector<int>&y) {
    if(mode.compare("eucledian")==0){
        return ComputationMethods::EucledianDistance(x,y);
    }
    else if(mode.compare("cosine")==0){
        return ComputationMethods::cosineDistance(x,y);
    }
}





