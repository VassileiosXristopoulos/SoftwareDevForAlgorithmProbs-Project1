#include "neutrino.h"
#include <iostream>
using namespace std;
neutrino::neutrino() :fermion(0.320, 0.5,"neutrino"){
	cout << "a neutrino has been constructed" << endl;
}
