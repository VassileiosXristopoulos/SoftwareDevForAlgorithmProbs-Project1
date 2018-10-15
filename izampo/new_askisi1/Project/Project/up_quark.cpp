
#include<iostream>
#include <string>
#include "up_quark.h"

	up_quark::up_quark(double mass,double spin,double electric_charge,std::string statistics)
	:mass(2.01),spin(0.5),electric_charge(0.6),statistics("Fermi Dirac"){
	std::cout<<"an up quark has been constructed"<<std::endl;
	}
	up_quark::~up_quark(){
	std::cout<<"an up quark has been destroyed"<<std::endl;
	}

	void up_quark::print(){
	std::cout<<"up quarks electric charge is:"<<electric_charge<<std::endl;
	std::cout<<"up quarks mass is:"<<mass<<std::endl;
	std::cout<<"up quarks spin is:"<<spin<<std::endl;
	std::cout<<"up quarks statistics is:"<<statistics<<std::endl;
	}
	int up_quark::up_electric_charge(){
		return electric_charge;
	}

