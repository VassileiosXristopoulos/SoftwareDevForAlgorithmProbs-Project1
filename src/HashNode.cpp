//
// Created by vassilis on 17/10/2018.
//

#include "../header/HashNode.h"

HashNode::HashNode(Item *item,vector<int> gvector) {
    my_item=item;
    gVector=gvector;
}

HashNode::~HashNode() {

}

vector<int> HashNode::getGvector(){
    return gVector;
}

string HashNode::getItemName(){
    return my_item->getName();
}

void HashNode::printGvector(){
    for(int i=0;i<gVector.size();i++){
        cout << gVector[i] << " ";
    }
}

Item *HashNode::getItem(){
    return my_item;
}