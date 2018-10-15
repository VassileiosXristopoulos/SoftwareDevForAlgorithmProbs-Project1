//
// Created by vassilis on 14/10/2018.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "../header/HashTable.h"
#include "../header/Item.h"
using namespace std;
HashTable::HashTable(int k, int size) { //TODO: implement hash table fundamental functionality

    TableSize = size;
    Table = new vector<Item*>[TableSize];
    H_vector= new hashFunction*[k];
    for( int i=0; i<k; i++){
       r_vector.push_back(rand());
       H_vector[i] = new hashFunction();
    }
}

HashTable::~HashTable() {

}

int HashTable::hash(Item *item) {
    unsigned long sum = 0;
    int M = (int)pow(2.0,32.0) -5;
    vector<int>h_i(r_vector.size());
    for( int i=0; i< r_vector.size() ; i++){
        h_i[i] = H_vector[i]->hash(item);
        sum += ((unsigned long)(r_vector[i]*h_i[i]))%M;
    }
    item->setGVector(h_i);
    return (int)(sum%TableSize) ;
}

void HashTable::add(Item* item) {
    int key = hash(item);
    Table[key].push_back(item);
}

void HashTable::print() {
    for(int i=0;i<TableSize;i++){
        cout<<"---------------------BUCKET "<< i <<"-------------------"<<endl;
        for(int j=0; j<Table[i].size(); j++){
            cout<<"             ----ELEMENT "<< j << "------"<<endl;
            cout<<"Name: "<< Table[i][j]->getName() << " Vector :";
            Table[i][j]->printContent();
            cout<<endl;
        }
    }
}

void HashTable::findCloser(Item *item) {
    double min_dist=-1;
    Item* closest_item=NULL;
    int bucket = hash(item);
    for(int i=0; i<Table[bucket].size(); i++){
        bool match = true;

        for(int j=0;j<item->getGVector().size(); j++){
            if( item->getGVector()[j] != Table[bucket][i]->getGVector()[j]){
                match=false;
                break;
            }

        }
        if(match){
           /* cout << "Item : " << item->getName() <<" with vector: ";
            item->printContent();
            cout<<endl;
            cout << "has same g(p) with Item: " << Table[bucket][i]->getName()<<" with vector: ";
            Table[bucket][i]->printContent();*/
           // cout<<endl<<endl;
            double distance=0;
            vector<int>query_vector=item->getContent();
            vector<int>data_vector=Table[bucket][i]->getContent();
            for(int j=0;j<query_vector.size(); j++){
                distance+= pow(data_vector[i]-query_vector[i],2);
            }
            distance = sqrt(distance);
            if(min_dist == -1){
                min_dist = distance;
                closest_item = Table[bucket][i];
            }
            else{
                if(min_dist>distance){
                    min_dist = distance;
                    closest_item = Table[bucket][i];
                }
            }
        }

    }
    if(min_dist>0 && closest_item!=NULL){
        cout<<"Closest item to "<<item->getName()<<" is item "<<closest_item->getName()<<" with distance: "
                                                                                         ""<<min_dist<<endl;
    }


}
