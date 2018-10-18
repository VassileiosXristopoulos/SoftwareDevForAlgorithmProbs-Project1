//
// Created by vassilis on 13/10/2018.
//

#include <cstdlib>
#include "../header/Item.h"
extern int k;
Item::Item(vector<string> &element){

    name = element.at(0);
    element.erase(element.begin());
    //cout<<"Created Item with name: "<< name << " and content ";
    for(int i=0;i<element.size();i++){
        content.push_back(atoi(element[i].c_str()));

   //     cout << element[i]<< " ";
    }
}


vector<int> &Item::getContent() {
    return content;
}
string Item::getName(){
    return name;
}
void Item::setGVector(vector<int>& h_i) {
    for(int i=0;i<g_vector.size(); i++){
        g_vector[i] = h_i[i];
    }
}

Item::~Item() {

}

void Item::printContent() {
    for(int i=0;i<content.size();i++){
        cout<<content[i]<<" ";
    }

}

vector<int>& Item::getGVector() {
    return g_vector;
}

void Item::printGVector(){
    for(int i=0;i< 4 ; i++){
        cout << g_vector[i] << " ";
    }
}






