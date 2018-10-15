
#include<iostream>
#include <string>
#include "down_quark.h"

		
	down_quark::down_quark(double mass ,double spin,double electric_charge)
	:mass(4.7),spin(0.5),electric_charge(-0.3){
	statistics="Fermi Dirac";
	std::cout<<"a down quark has been constructed"<<std::endl;
	}
	
	down_quark::~down_quark(){
	std::cout<<"a down quark has been distroyed"<<std::endl;
	}	
	
	void down_quark::print(){
	std::cout<<"down quarks mass is:"<<mass<<std::endl;
	std::cout<<"down quarks spin is:"<<spin<<std::endl;
	std::cout<<"down quarks statistics is:"<<statistics<<std::endl;
	std::cout<<"down quarks electric charge is:"<<electric_charge<<std::endl;	
	}
	int down_quark::down_electric_charge(){
		return electric_charge;
	}
