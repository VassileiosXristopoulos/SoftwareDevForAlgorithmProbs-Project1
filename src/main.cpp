
// Created by vassilis on 12/10/2018.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <ctime>
#include <iterator>
#include <cstdlib>
#include <vector>
#include "../header/DataSetMap.h"
#include "../header/Item.h"
#include "../header/HashTable.h"

#include <direct.h>
//TODO : make a class where I will save all input set (i.e. map of vectors) with get element, (set element)
using namespace std;
int d,r;
int main(int argv,char **argc){
    srand(time(NULL));
    int a, b , k, L, n=0;
    string FileLine;
    string inputFile, queryFile, outputFile;

    if( argv == 11 ){ // TODO: ask/implement different ways of getting arguments (asking user)
        if(argc[2]==NULL || argc[4]==NULL || argc[6]==NULL || argc[8]==NULL || argc[10]==NULL ){
            cout << "Invalid Arguments" << endl;
            return 1;
        }
        string s = "Input\\";

        inputFile = "Input\\" + string(argc[2]);
        queryFile = "Input\\" + string(argc[4]);
        k = atoi(argc[6]);
        L = atoi(argc[8]);
        if( k<=0 || L<=0 ){
            cout << "k and/or L arguments not given properly" << endl;
            return 1;
        }
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
    else {
        cout << "Wrong arguments!" << endl;
        return 1;
    }


   vector<Item*>Map;
    char buff[FILENAME_MAX];
    getcwd( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    std::cout << "Current Directory: " << current_working_dir << std::endl;
    string input_file = "X:\\di-project\\SoftwareDevForAlgorithmProbs-Project1\\Input\\input_small.txt";

    ifstream input(input_file.c_str());

    string mode;
    std::getline(input,mode); //get mode (i.e. first line)
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

        Item *item = new Item(element);

        if(element.size()<=0){
            cout <<"element empty!!"<<endl;
            continue;
        }
        Map.push_back(item);

        d = element.size();
        n++;

    }
    HashTable ** TableArray = new HashTable*[L];
    for(int i=0; i<L ; i++){
        TableArray[i] = new HashTable(k,n/2);
        for(int j=0; j<Map.size(); j++){
            TableArray[i]->add(Map[j]);
        }
    }
    cout << "out!!"<<endl;
  //  TableArray[0]->print();
    string output_file = "X:\\di-project\\SoftwareDevForAlgorithmProbs-Project1\\Input\\query_small.txt";
    ifstream query_input(output_file.c_str());
    string radius;
    std::getline(query_input,radius); // get radius (i.e. first line)
    //int r = stoi(radius);
    r=stoi(radius.substr(radius.find(":") + 1));
   // vector<vector<Item*>>ClosestItems;
    pair<Item *,double>closestNeighboor(NULL,-1.0);
    vector<pair<Item *,double>> closerNneighboors;
    while ( std::getline(query_input, FileLine) ) { // TODO: implement functionality of checking first line for mode
       // cout <<"in"<<endl;
        istringstream iss(FileLine);
      //  if (!(iss >> a >> b)) { break; } // error
        string line = FileLine.substr(0, FileLine.size() - 1);
        vector<string> element;
        size_t pos = line.find(' ');
        size_t startPos = 0;
        while (pos != string::npos) {
            element.push_back(line.substr(startPos, pos - startPos));
            startPos = pos + 1;
            pos = line.find(' ', startPos);
        }
        Item *item = new Item(element);
        //vector<Item*>ClosestNeighboors;
        vector<Item*>ClosestRNeighboors;
        for(int i=0;i<L;i++){
            //vector<pair<Item *,double>>neighboors=TableArray[i]->findCloser(item);
            if(neighboors.size()>0){
                if()
              //  ClosestNeighboors.push_back(neighboors[0]);
                for(int k=1;k<neighboors.size();k++){
                    ClosestRNeighboors.push_back(neighboors[k]);
                }
            }
        }


        //TODO: search for similar with "item"

    }
}

int getMin(vector<int>Vector){
    int min;
    for(int i=0;i<Vector.size();i++){

    }
}
