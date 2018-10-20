#include <utility>

//
// Created by vassilis on 20/10/2018.
//

#include "../header/CubeIndex.h"

CubeIndex::CubeIndex(vector<int>index) {
    this->index = std::move(index);
}

CubeIndex::~CubeIndex() {

}

vector<int> CubeIndex::content() {
    return index;
}


