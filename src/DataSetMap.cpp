//
// Created by vassilis on 13/10/2018.
//

#include <sstream>
#include <fstream>
#include "../header/DataSetMap.h"
#include "../header/ComputationMethods.h"

int d,n;
DataSetMap::DataSetMap() = default;

DataSetMap::~DataSetMap() = default;


void DataSetMap::append(Item * item) {
    Map.push_back(item);
}



double DataSetMap::TrueDistance(Item *item,string mode) {
    double min=-1;
    for( int i=0; i<Map.size(); i++ ){
        double dist;
        if(mode.compare("eucledian")==0){
            dist= ComputationMethods::EucledianDistance(item->getContent(),Map[i]->getContent());
        }
        else if(mode.compare("cosine")==0){
            dist=ComputationMethods::cosineDistance(item->getContent(),Map[i]->getContent());
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
    cout<<mode<<endl;
    while ( std::getline(input, FileLine) ) { // TODO: implement functionality of checking first line for mode
        //  cout<<"in`"<<endl;
        istringstream iss(FileLine);
        //if (!(iss >> a >> b)) { break; } // error
        string line = FileLine.substr(0, FileLine.size() - 1);
        vector<string> element;
        size_t pos = line.find(' ');
        size_t startPos = 0;
        while (pos != string::npos) {
            element.push_back(line.substr(startPos, pos - startPos));
            startPos = pos + 1;
            pos = line.find(' ', startPos);
        }
        element.push_back(line.substr(startPos, pos - startPos));
        Item *item = new Item(element);

        if(element.size()<=0){
            cout <<"element empty!!"<<endl;
            continue;
        }
        Map.push_back(item);

        d = element.size();
        n++;

    }
    return mode;
}






