#ifndef ELECTRON_H
#define ELECTRON_H
#include "fermion.h"
#include <iostream>
using namespace std;
class electron :public fermion{
//	char *id;
public:
	electron();
	~electron(){
		cout << "an electron has been destroyed" << endl;
	}
};
#endif
