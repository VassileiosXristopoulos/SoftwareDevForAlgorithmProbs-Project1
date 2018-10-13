//
// Created by vassilis on 13/10/2018.
//

#include <cstdlib>
#include "../header/Item.h"

Item::Item(vector<string> &element){
    name = element.at(0);
    element.erase(element.begin());

    cout<<"Created Item with name: "<< name << " and content ";
    for(int i=0;i<element.size();i++){
        content.push_back(atoi(element[i].c_str()));
        cout << element[i]<< " ";
    }
    cout<<endl;
}
Item::~Item() {}

vector<int> &Item::getContent() {
    return content;
}
string Item::getName(){
    return name;
}


