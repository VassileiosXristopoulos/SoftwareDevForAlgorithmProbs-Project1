
#include<iostream>
#include <string>
#include "neutron.h"


/*constructor*/
	neutron::neutron(int electric_charge,double mass,int quarks,double spin,std::string statistics)
	:electric_charge(0),mass(1.0085),quarks(3),spin(0.5),statistics("Fermi Dirac"){
	total=electric_charge+up_quark2.up_electric_charge()+(-1)*down_quark2.down_electric_charge()+(-1)*down_quark3.down_electric_charge()+gluon2.gluon_electric_charge()+gluon3.gluon_electric_charge()+gluon4.gluon_electric_charge();
	std::cout<<"a neutron has been constructed"<<std::endl;
	
}
/* */
neutron::~neutron(){
	std::cout<<"a neutron has been destoyed"<<std::endl;
}

void neutron::print(){
	up_quark2.print();
	down_quark2.print();
	down_quark3.print();
	gluon2.print();
	gluon3.print();
	gluon4.print();
	std::cout<<"neutrons mass is:"<<mass<<std::endl;
	std::cout<<"neutrons spin is:"<<spin<<std::endl;
	std::cout<<"neutrons electric charge is:"<<electric_charge<<std::endl;
	std::cout<<"neutrons statistics is:"<<statistics<<std::endl;
}
int neutron::getTotal(){
	return total;
}
