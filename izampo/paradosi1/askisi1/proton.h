#include "neutron.h"
#include <iostream>
#include <string>

class proton{
	private:
	int quarks;
	double mass;
	double spin;
	std::string statistics;
	int electric_charge;
	int total;
	down_quark down_quark4;
	up_quark up_quark3;
	up_quark up_quark4;
	gluon gluon5;
	gluon gluon6;
	gluon gluon7;
	public: 
	proton(int quarks=3,double mass=1.007,double spin=0.5,int electric_charge=1,std::string statistics="Fermi Dirac");
	~proton();
	void print();
	int electricFunct(int,int);
	int getTotal();
};
