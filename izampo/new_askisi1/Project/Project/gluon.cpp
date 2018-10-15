
#include<iostream>
#include <string>
#include "gluon.h"

	gluon::gluon(int electric_charge,double mass,double spin,std::string statistics)
	:electric_charge(0),mass(0),spin(1),statistics("Bose-Einstein"){
	std::cout<<"a gluon has been constructed"<<std::endl;
	}
	gluon::~gluon(){
	std::cout<<"a gluon has been destroyed"<<std::endl;
	}
	void gluon::print(){
	std::cout<<"gluons electric charge is:"<<electric_charge<<std::endl;
	std::cout<<"gluons mass is:"<<mass<<std::endl;
	std::cout<<"gluons spin is:"<<spin<<std::endl;
	std::cout<<"gluons statistics is:"<<statistics<<std::endl;
	}
	int gluon::gluon_electric_charge(){
		return electric_charge;
	}
