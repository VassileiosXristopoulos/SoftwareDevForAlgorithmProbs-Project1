#include <iostream>
#include <string>
class electron{
	private:
	int electric_charge;
	double mass;
	int spin;
	std::string statistics;
	public:
		electron(int electric_charge=-1,double mass=0.000548579909070,double spin=0.5,std::string statistics="Fermi Dirac");
		~electron();
		void print();
		int get_charge();
};
