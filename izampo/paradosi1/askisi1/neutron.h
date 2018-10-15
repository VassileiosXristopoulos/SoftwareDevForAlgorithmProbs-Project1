#include "gluon.h"
#include "down_quark.h"
#include "up_quark.h"
#include <iostream>
#include <string>
class neutron{
	private:
 	int electric_charge;
 	int up_quarks;
 	int down_quarks;
 	int gluons;
 	int mass;
	int quarks;
	int spin;
	std::string statistics;
	int total;
	down_quark down_quark2;
	down_quark down_quark3;
	up_quark up_quark2;
	gluon gluon2;
	gluon gluon3;
	gluon gluon4;
	public:
	
	neutron(int electric_charge=0,double mass=1.0085,int quarks=3,double spin=0.5,std::string statistics="Fermi Dirac");
	~neutron();
	void print();
	int getTotal();
};
