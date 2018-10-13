//
// Created by vassilis on 12/10/2018.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <zconf.h>
#include <experimental/filesystem>
#include <iterator>
#include <cstdlib>
#include <vector>


//TODO : make a class where I will save all input set (i.e. map of vectors) with get element, (set element)
using namespace std;

int main(int argv,char **argc){
    int a, b;
    string FileLine;
    std::string mycwd(getenv("PWD"));
    std::cout << "Current Directory: " << mycwd << std::endl;

    ifstream input("../SoftwareDevForAlgorithmProbs-Project1/Input/input_small");
    while ( std::getline(input, FileLine) ){
        istringstream iss(FileLine);
        if (!(iss >> a >> b)) { break; } // error
        string line = FileLine.substr(0, FileLine.size()-1);

        istringstream isss(line);

        vector<string> results(istream_iterator<string>{isss},
                                         istream_iterator<string>());

        cout <<endl;
    }
}