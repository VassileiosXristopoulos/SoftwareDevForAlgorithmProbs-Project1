
#include<iostream>
#include <string>
#include "electron.h"

	electron::electron(int electric_charge,double mass,double spin,std::string statistics)
	:electric_charge(-1),mass(0.000548579909070),spin(0.5),statistics("Fermi Dirac"){
	std::cout<<"an electron has been constructed"<<std::endl;
	}
 	electron::~electron(){
	std::cout<<"an electron has been destroyed"<<std::endl;
	}
	void electron::print(){
	std::cout<<"electron mass is:"<<mass<<std::endl;
	std::cout<<"electron spin is:"<<spin<<std::endl;
	std::cout<<"electron electric charge is:"<<electric_charge<<std::endl;
	std::cout<<"electron statistics is:"<<statistics<<std::endl;
	}
	int electron::get_charge(){
		return (-1)*electric_charge;
	}


