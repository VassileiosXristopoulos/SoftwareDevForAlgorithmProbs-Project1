#include <iostream>
#include <string>
class up_quark{
	private:
	double mass;
	double spin;
	std::string statistics;
	double electric_charge;
	public:	
		up_quark(double mass=2.01,double spin=0.5,double electric_charge=0.6,std::string statistics="Fermi Dirac");
		~up_quark();
		void print();
		int up_electric_charge();
};
