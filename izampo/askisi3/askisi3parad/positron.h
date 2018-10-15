#ifndef POSITRON_H
#define POSITRON_H
#include "fermion.h"
#include <iostream>
using namespace std;
class positron :public fermion{
//	char *id;
public:
	positron();
	~positron(){
		cout << "a positron has been destroyed" << endl;
	}
};
#endif
