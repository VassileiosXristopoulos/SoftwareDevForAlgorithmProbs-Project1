#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class particle{
private:
	double mass;
	double spin;
	double electric_charge;
	string id;
public:
	particle(double, double, double,string&);
	particle(string&,double,double,double);
	string& get_id();
	double get_charge();
	double get_mass();
	double get_spin();
	void interactions(vector<particle*>&,int,int);
	virtual ~particle();
};
#endif
