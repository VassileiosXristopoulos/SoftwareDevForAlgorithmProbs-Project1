
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
#include "../../header/DataSetMap.h"
#include "../../header/Item.h"
#include "../../header/lsh/EucledianHashTable.h"
#include "../../header/lsh/CosineHashTable.h"
#include "../../header/ComputationMethods.h"

using namespace std;
extern int d,n;
int r,L,k,w=100;
default_random_engine generator;
normal_distribution<float> distribution(0,1);
int main(int argv,char **argc){
    srand(time(NULL));

    string inputFile, queryFile, outputFile,radius;

    if( argv == 11 ){ // TODO: ask/implement different ways of getting arguments (asking user)
        if(argc[2]==NULL || argc[4]==NULL || argc[6]==NULL || argc[8]==NULL || argc[10]==NULL ){
            cout << "Invalid Arguments" << endl;
            return 1;
        }
        string s = "Input/";

        inputFile = "Input/" + string(argc[2]);
        queryFile = "Input/" + string(argc[4]);
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
    AHashTable * TableArray[L];
    for( int i=0; i<L ; i++){
        if(mode.compare("eucledian")==0) {
            TableArray[i] = new EucledianHashTable(k, n / 2);
        }
        else{
            TableArray[i] = new CosineHashTable( n / 2, k);
        }
        for( int j=0; j<Map.size(); j++){
            TableArray[i]->add(Map.at(j));
        }
    }



    ifstream input_q(queryFile);
    getline(input_q,radius); // get radius (i.e. first line)
    r=stoi(radius.substr(radius.find(":") + 1));

    double max_div = 0;
    string line;
    for( std::string FileLine; getline( input_q, FileLine ); ) {
        double tLSH,tTrue;

        line = FileLine.substr(0, FileLine.size() - 1);
        vector<string> element = ComputationMethods::Split(line);

        Item *item = new Item(element);
        pair<Item *,double>closestNeighboor(NULL,-1.0);
        vector<string> closerNneighboors;

        for( int i = 0; i < L ; i++ ){
            vector<string> Nneighboors=TableArray[i]->findNcloserNeighbors(item);

            clock_t nearest_start = clock();
            pair<Item*,double>neighboor = TableArray[i]->findCloserNeighbor(item);
            clock_t nearest_end = clock();
            tLSH = (nearest_end-nearest_start)/ (double) CLOCKS_PER_SEC;

            if(neighboor.second>0){ //last item is the closest neighboor

                if(closestNeighboor.second==-1 || neighboor.second < closestNeighboor.second){
                    closestNeighboor=neighboor;
                }

                for(unsigned int j = 0 ; j < Nneighboors.size() ; j++ ){
                    closerNneighboors.push_back(Nneighboors[j]);
                }
            }
        }
        if(closestNeighboor.second>0){
            cout << "Query item: " << item->getName() << endl;
            //sort and remove duplicates from set of closer neighbors
            sort( closerNneighboors.begin(), closerNneighboors.end() );
            closerNneighboors.erase(unique( closerNneighboors.begin(), closerNneighboors.end() ), closerNneighboors
           .end() );

            cout << "R-near neighbor:"<<endl;
            if(closerNneighboors.size()==0)
                cout<<"none"<<endl;


            for(unsigned int j = 0; j < closerNneighboors.size(); j++ ){
                if(closerNneighboors[j].compare(closestNeighboor.first->getName())!=0){
                    cout << closerNneighboors[j] << endl;
                }
            }

            cout << "Nearest neighbor: " <<closestNeighboor.first->getName()<<endl<<
            "distanceLSH: "<<closestNeighboor.second<<endl;

            clock_t true_start = clock();
            double trueDist = Map.TrueDistance(item,mode);
            clock_t  true_end = clock();
            tTrue = (true_end-true_start)/ (double) CLOCKS_PER_SEC;

            cout << "distanceTrue: "<< trueDist << endl;
            cout << "tLSH: " << tLSH<<endl;
            cout << "tTrue: " << tTrue<<endl;
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


