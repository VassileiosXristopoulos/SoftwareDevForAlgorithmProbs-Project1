#include "proton.h"
#include<iostream>
class nucleus{
	private:
		int total_charge;
		int num;
		proton protons1;
		proton protons2;
		proton protons3;
		proton protons4;
		proton protons5;
		proton protons6;
		neutron **pt;
	public:
	nucleus(int);
	~nucleus();
	void print();
	int total_electric_charge();
	int total_protons();
	int total_neutrons();
	//int number();
};
