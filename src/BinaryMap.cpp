//
// Created by vassilis on 20/10/2018.
//

#include "../header/BinaryMap.h"

void BinaryMap::add(int num, char val) {
    Map.insert(pair<int,char>(num,val));
}
bool BinaryMap::inMap(int num){
    return Map.find(num) != Map.end();
}
int BinaryMap::get(int num) {
    return Map.at(num);
}

