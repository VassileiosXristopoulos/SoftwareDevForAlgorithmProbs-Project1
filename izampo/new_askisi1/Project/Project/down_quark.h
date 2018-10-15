#include <iostream>
#include <string>
class down_quark{
	private:
	double mass;
	double spin;
	std::string statistics;
	double electric_charge;
	public:
		down_quark(double mass= 4.7 ,double spin=0.5,double electric_charge=-0.3);
		~down_quark();
		void print();
		int down_electric_charge();
};
