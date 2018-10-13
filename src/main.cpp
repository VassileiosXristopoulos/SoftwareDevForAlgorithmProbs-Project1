//
// Created by vassilis on 12/10/2018.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <zconf.h>
#include <iterator>
#include <cstdlib>
#include <vector>
#include "../header/DataSetMap.h"
#include "../header/Item.h"

//TODO : make a class where I will save all input set (i.e. map of vectors) with get element, (set element)
using namespace std;

int main(int argv,char **argc){
    int a, b , k, L;
    string FileLine;
    string inputFile, queryFile, outputFile;

    if( argv == 11 ){
        if(argc[2]==NULL || argc[4]==NULL || argc[6]==NULL || argc[8]==NULL || argc[10]==NULL ){
            cout << "Invalid Arguments" << endl;
            return 1;
        }
        string s = "Input/";

        inputFile = "Input/" + string(argc[2]);
        queryFile = "Input/" + string(argc[4]);
        k = atoi(argc[6]);
        L = atoi(argc[8]);
        outputFile = "Input/" + string(argc[10]);
    }
    else if( argv == 9){
        if(argc[2]==NULL || argc[4]==NULL || argc[10]==NULL){
            cout << "Invalid Arguments" << endl;
            return 1;
        }
        inputFile = "Input/" + string(argc[2]);
        queryFile = "Input/" + string(argc[4]);
        k = 4;
        L = 5;
        outputFile = "Input/" + string(argc[10]);
    }




   // DataSetMap *Map = new DataSetMap();
   vector<Item>Map;
    ifstream input(inputFile.c_str());
    while ( std::getline(input, FileLine) ){
        istringstream iss(FileLine);
        if (!(iss >> a >> b)) { break; } // error
        string line = FileLine.substr(0, FileLine.size()-1);
        vector <string> element;
        size_t pos  = line.find(' ');
        size_t startPos = 0;
        while( pos != string::npos){
            element.push_back( line.substr( startPos, pos - startPos));
            startPos = pos + 1;
            pos = line.find(' ', startPos);
        }
        Item * item = new Item(element);
        Map.push_back(*item);
     //   Map->Insert(*item);
        //hash table insert( item );
    }

}