
#include<iostream>
#include <string>
#include "proton.h"


	proton::proton(int quarks,double mass,double spin,int electric_charge,std::string statistics):
	quarks(3),mass(1.007),spin(0.5),electric_charge(1),statistics("Fermi Dirac"){
	total=electric_charge+(-1)*down_quark4.down_electric_charge()+up_quark3.up_electric_charge()+up_quark4.up_electric_charge()+gluon5.gluon_electric_charge()+gluon6.gluon_electric_charge()+gluon7.gluon_electric_charge();
	std::cout<<"a proton has been constructed"<<std::endl;
}
void proton::print(){
	std::cout<<"protons mass is:"<<mass<<std::endl;
	std::cout<<"protons spin is:"<<spin<<std::endl;
	std::cout<<"protons electric charge is:"<<electric_charge<<std::endl;
	std::cout<<"protons statistics is:"<<statistics<<std::endl;
	down_quark4.print();
	up_quark3.print();
	up_quark4.print();
	gluon5.print();
	gluon6.print();
	gluon7.print();
}
proton::~proton(){
	std::cout<<"a proton has been destroyed"<<std::endl;
}
int proton::electricFunct(int up_quarks,int down_quarks){
	return ( (up_quarks*(2/3)) +(down_quarks*(-1/3)) );
}

int proton::getTotal(){
	return total;
}