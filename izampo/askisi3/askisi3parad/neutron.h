#ifndef NEUTRON_H
#define NEUTRON_H
#include "proton.h"
#include <iostream>
#include <string>
using namespace std;
class neutron :public fermion{
	
public:
	neutron();
	~neutron(){
		cout << "a neutron has been destroyed" << endl;
	}
};
#endif
