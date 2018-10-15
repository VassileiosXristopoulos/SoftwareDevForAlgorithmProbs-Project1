#include "neutrino.h"
#include <iostream>
using namespace std;
neutrino::neutrino() :fermion("neutrino",0.320, 0.5){
	cout << "a neutrino has been constructed and its statistics is "<<get_statistics() << endl;
}
