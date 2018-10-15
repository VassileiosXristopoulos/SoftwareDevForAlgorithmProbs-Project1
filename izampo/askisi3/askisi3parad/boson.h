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
	boson(string my_id="no_name", double spinvar=0,double massVar = 0, double chargeVar = 0);
	string& get_statistics();
	~boson();
};
#endif
