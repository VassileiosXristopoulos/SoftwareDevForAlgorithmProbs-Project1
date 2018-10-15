
#include "proton.h"
#include <iostream>
using namespace std;
proton::proton() :fermion(938.27208, 1, 0.5,"proton"){
	cout << "a proton has been constructed" << endl;
}
proton::~proton(){
	cout << "a proton has been destroyed" << endl;
}
