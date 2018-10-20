//
// Created by vassilis on 20/10/2018.
//
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <ctime>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "../header/DataSetMap.h"
#include "../header/Item.h"
#include "../header/Hypercube.h"

using namespace std;
int r,M,k;
default_random_engine generator;
normal_distribution<float> distribution(0,1);
extern int d,n;
int main(int argv,char **argc) {
    srand(time(NULL));
    int probes;
    string FileLine;
    string inputFile, queryFile, outputFile;

    if( argv == 13 ){ // TODO: ask/implement different ways of getting arguments (asking user)
        if(argc[2]==NULL || argc[4]==NULL || argc[6]==NULL || argc[8]==NULL || argc[10]==NULL || argc[12]==NULL ){
            cout << "Invalid Arguments" << endl;
            return 1;
        }
        string s = "Input/";

        inputFile = "../Input/" + string(argc[2]);
        queryFile = "../Input/" + string(argc[4]);
        k = atoi(argc[6]);
        M = atoi(argc[8]);
        if( k<=0 || M<=0 ){
            cout << "k and/or M arguments not given properly" << endl;
            return 1;
        }
        probes = atoi(argc[10]);
        outputFile = "Input/" + string(argc[12]);
    }
    else if( argv == 11){
        if(argc[2]==NULL || argc[4]==NULL || argc[10]==NULL){
            cout << "Invalid Arguments" << endl;
            return 1;
        }
        inputFile = "Input/" + string(argc[2]);
        queryFile = "Input/" + string(argc[4]);
        k = 3;
        M = 10;
        probes = 2;
        outputFile = "Input/" + string(argc[12]);
    }
    else {
        cout << "Wrong arguments!" << endl;
        return 1;
    }

    DataSetMap Map;
    string mode = Map.InsertFile(inputFile);
    //(int)log2(n)
    Hypercube *hypercube = new Hypercube(13,mode);
    for(int i=0;i<Map.size() ;i++){
        hypercube->add(Map.at(i));
    }
    ifstream input_q(queryFile);
    string radius;
    getline(input_q,radius); // get radius (i.e. first line)

    r=stoi(radius.substr(radius.find(":") + 1));
    cout << radius <<endl;
    r=stoi(radius.substr(radius.find(":") + 1));
    double max_div = 0;
    while ( getline(input_q, FileLine) ) { // TODO: implement functionality of checking first line for mode
        istringstream iss(FileLine);

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
        pair<string,double>closer_item;
        double trueDist = Map.TrueDistance(item,mode);
        closer_item = hypercube->findCloser(item,100,5);
        vector<pair<string,double>>Rnearest = hypercube->findEuclRCloser(item,100,5,r);
        cout <<"Query item: "<< item->getName()<<endl;
        cout <<"R-nearest neighbor:"<<endl;
        for(int i=0 ; i<Rnearest.size(); i++){
            cout<<Rnearest[i].first << ": "<<Rnearest[i].second<<endl;
        }
        cout<< "Nearest neighbor: "
        ": "<< closer_item.first <<endl<<"distance Hypercube: "<< closer_item.second << endl<<
        "distanceTrue: " << trueDist<<endl<<endl;
        double div = closer_item.second/trueDist;
        if(div>max_div)
            max_div=div;

    }
    cout << "Max Div: "<<max_div<<endl;
}
