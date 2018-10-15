#include <iostream>
#include <string>
class gluon{
	
	private:
	int electric_charge;
	double mass;
	double spin;
	std::string statistics;
	
	public:
	gluon(int electric_charge=0,double mass=0,double spin=1,std::string statistics="Bose-Einstein");
	~gluon();
	void print();
	int gluon_electric_charge();
};
