#ifndef FERMION_H
#define FERMION_H
#include "particle.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class fermion:public particle{
private:
	string statistics;
public:
	fermion(double massVar = 0, double chargeVar = 0, double spinVar = 0, string my_id="no_name");
	fermion(string my_id="no_name",double massVar = 0, double spinVar = 0, double chargeVar = 0);
	string& get_statistics();
	~fermion();
};
#endif
