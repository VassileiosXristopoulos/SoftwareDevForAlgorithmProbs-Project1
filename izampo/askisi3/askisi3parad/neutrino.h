#ifndef NEUTRINO_H
#define NEUTRINO_H
#include "fermion.h"
#include <iostream>
using namespace std;
class neutrino :public fermion{
//	char *id;
public:
	neutrino();
	~neutrino(){
		cout << "a neutrino has been destroyed" << endl;
	}
};
#endif
