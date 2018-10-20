#include <utility>

//
// Created by vassilis on 20/10/2018.
//

#include "../header/CubeEdge.h"
#include "../header/ComputationMethods.h"
CubeEdge::CubeEdge(vector<int> index) {
    this->index = new CubeIndex(std::move(index));
}

CubeEdge::~CubeEdge() {

}

void CubeEdge::add(Item *item) {
    elements.push_back(item);
}

vector<Item *> CubeEdge::Elements() {
    return elements;
}

CubeIndex *CubeEdge::getIndex() {
    return index;
}

