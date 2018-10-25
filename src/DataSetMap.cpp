//
// Created by vassilis on 13/10/2018.
//

#include <sstream>
#include <fstream>
#include "../header/DataSetMap.h"
#include "../header/Util.h"

int d,n;
DataSetMap::DataSetMap() = default;

DataSetMap::~DataSetMap() {
    for(unsigned int i=0; i<Map.size(); i++){
        delete(Map[i]);
    }
}


void DataSetMap::append(Item * item) {
    Map.push_back(item);
}



double DataSetMap::TrueDistance(Item *item,string mode) {
    double min=-1;
    for (auto &i : Map) {
        double dist;
        if(mode == "eucledian"){
            dist= Util::EucledianDistance(item->getContent(), i->getContent());
        }
        else if(mode == "cosine"){
            dist=Util::cosineDistance(item->getContent(), i->getContent());
        }
        if(min==-1 || dist<min)
            min = dist;
    }
    return min;
}

int DataSetMap::size(){
    return static_cast<int>(Map.size());
}

Item *DataSetMap::at(int index) {
    return Map[index];
}

string DataSetMap::InsertFile(string inputFile) {
    string FileLine;
    ifstream input(inputFile);
    n=0;

    string mode;
    std::getline(input,mode); //get mode (i.e. first line)
    cout<<"mode:"<<mode<<endl;

    for( std::string line; getline( input, FileLine ); ) {

        line = FileLine.substr(0, FileLine.size() - 1);
        vector<string> element = Util::Split(line);
        Item *item = new Item(element);

        if(element.size()<=0){
            cout <<"element empty!!"<<endl;
            continue;
        }
        Map.push_back(item);

        d = static_cast<int>(element.size());
        n++;
     //   free(FileLine);

    }
    return mode;
}






