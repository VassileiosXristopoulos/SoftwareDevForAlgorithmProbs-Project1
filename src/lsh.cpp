
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
#include <algorithm>
#include <iomanip>
#include "../header/DataSetMap.h"
#include "../header/Item.h"
#include "../header/HashTable.h"

//TODO : make a class where I will save all input set (i.e. map of vectors) with get element, (set element)
using namespace std;
extern int d,n;
int r,L,k;
default_random_engine generator;
normal_distribution<float> distribution(0,1);
int main(int argv,char **argc){
    srand(time(NULL));

    string inputFile, queryFile, outputFile;

    if( argv == 11 ){ // TODO: ask/implement different ways of getting arguments (asking user)
        if(argc[2]==NULL || argc[4]==NULL || argc[6]==NULL || argc[8]==NULL || argc[10]==NULL ){
            cout << "Invalid Arguments" << endl;
            return 1;
        }
        string s = "Input/";

        inputFile = "../Input/" + string(argc[2]);
        queryFile = "../Input/" + string(argc[4]);
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

    cout << inputFile << "  " << queryFile<<endl;
   DataSetMap Map;
    string mode = Map.InsertFile(inputFile);

    HashTable ** TableArray = new HashTable*[L];

    for(int i=0; i<L ; i++){
        TableArray[i] = new HashTable(i,k,n/2,mode);
        for(int j=0; j<Map.size(); j++){
            TableArray[i]->add(Map.at(j),mode);
        }
    }


    ifstream input_q(queryFile);
    string radius;
    getline(input_q,radius); // get radius (i.e. first line)

    r=stoi(radius.substr(radius.find(":") + 1));
    string FileLine;
    cout << radius <<endl;
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
      //  cout << item->getContent().size() <<endl;
        pair<Item *,double>closestNeighboor(NULL,-1.0);
        vector<pair<Item *,double>> closerNneighboors;
        for(int i=0;i<L;i++){
          //  cout << "HASHTABLE["<<i+1<<"]"<<endl;
            vector<pair<Item *,double>> Nneighboors=TableArray[i]->findNCloserNeighbrs(item,mode);
            pair<Item*,double>neighboor = TableArray[i]->findCloserNeighbor(item,mode);
            if(neighboor.second>0){ //last item is the closest neighboor
                if(closestNeighboor.second==-1 || neighboor.second < closestNeighboor.second){
                    closestNeighboor=neighboor;
                }
          //  vector<pair<Item*,double >> neighboors=TableArray[i]->findNCloser(item);
                for(int j=0;j<Nneighboors.size();j++){

                    closerNneighboors.push_back(Nneighboors[j]);
                }
            }
        }
        if(closestNeighboor.second>0){
            cout << "Query item: " << item->getName() << endl;
            vector<string>Names;
          //  for(int l=0;l< closerNneighboors.size(); l++){
          //      Names.push_back(closerNneighboors[l].first->getName());
          //  }
            sort( closerNneighboors.begin(), closerNneighboors.end() );
            closerNneighboors.erase(unique( closerNneighboors.begin(), closerNneighboors.end() ), closerNneighboors
           .end() );


            cout << "R-near neighbor:"<<endl;
            if(closerNneighboors.size()==0)
                cout<<"none"<<endl;


            for(int j=0;j<closerNneighboors.size(); j++){
                if(closerNneighboors[j].first->getName().compare(closestNeighboor.first->getName())!=0){
                    cout << closerNneighboors[j].first->getName() << " : "<< closerNneighboors[j].second <<endl;
                }

            }
            cout << "Nearest neighbor: " <<closestNeighboor.first->getName()<<endl<<
            "distanceLSH: "<<closestNeighboor.second<<endl;
            double trueDist = Map.TrueDistance(item,mode);
            cout << "distanceTrue: "<< trueDist << endl;
            cout<<endl;
            double div = closestNeighboor.second/trueDist;
            if(div > max_div){
                max_div = div;
            }
        }
        else{
            if(closerNneighboors.size()>0){
                cout << "Error occured at finding neighboors. Found Ncloser without finding closer"<<endl;
                exit(0);
            }
        }


    }
    cout << "Max Div: "<<max_div<<endl;


}


