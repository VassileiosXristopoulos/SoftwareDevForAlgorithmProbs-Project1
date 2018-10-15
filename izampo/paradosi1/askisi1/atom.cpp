
#include<iostream>
#include <string>
#include <ctime>
#include<cstdlib>
#include "atom.h"

	
		atom::atom(int number,int atomic_number,int protons,int electric_charge)
		: atomic_number(6),protons(6),electric_charge(0),nucleus1(number){
		neutrons = number;
		mass_number=atomic_number+neutrons;
		total = electrons1.get_charge()+electrons2.get_charge()+electrons3.get_charge()+electrons4.get_charge()+electrons5.get_charge()+electrons6.get_charge() +nucleus1.total_electric_charge() ;
		std::cout << "an atom has been constructed" << std::endl;
	}
		atom::~atom(){
		std::cout << "atoms mass number is:"<<get_mass_number() << std::endl;
		std::cout << "atoms atomic number is:"<<get_atom_number() << std::endl;
		std::cout<<"an atom has been destroyed"<<std::endl;
		}
		void atom::print(){
		std::cout<<"the atomic number is:"<<get_atom_number() <<std::endl;
		std::cout<<"the mass number is:"<<get_mass_number()<<std::endl;
		std::cout << "atoms electric charge is:"<<get_electric_charge() << std::endl;
		nucleus1.print();
		electrons1.print();
		electrons2.print();
		electrons3.print();
		electrons4.print();
		electrons5.print();
		electrons6.print();
		}
		int atom::get_atom_number(){
			return atomic_number;
		}
		int atom::get_mass_number(){
			return mass_number;
		}
		int atom::get_electric_charge(){
			return electric_charge;
		}
		int atom::total_electric_charge(){
			return total;
		}
		int atom::get_Protons(){
			return protons;
		}
		int atom::get_Neutrons(){
			return neutrons;
		}

			


