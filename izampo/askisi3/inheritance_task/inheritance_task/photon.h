#ifndef PROTON_H
#define PROTON_H
#include "boson.h"
#include <iostream>
using namespace std;
class photon :public boson{
//	char *id;
public:
	photon();
	~photon(){
		cout << "a photon has been destroyed" << endl;
	}
};
#endif
