#ifndef ANTINEUTRINO_H
#define ANTINEUTRINO_H
#include "fermion.h"
#include <iostream>
#include <string>
using namespace std;
class antineutrino :public fermion{
public:
	antineutrino();
	~antineutrino(){
		cout << "an antineutrino has been destroyed" << endl;
	}
};
#endif

