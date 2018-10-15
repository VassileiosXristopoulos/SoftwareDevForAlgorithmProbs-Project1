#ifndef BOSON_H
#define BOSON_H
#include "particle.h"
#include <string>
#include <iostream>
using namespace std;
class boson :public particle{
private:
	string statistics;
public:
	boson(int spinVar = 0, string my_id="no name",double massVar = 0, double chargeVar = 0);
	~boson();
};
#endif
