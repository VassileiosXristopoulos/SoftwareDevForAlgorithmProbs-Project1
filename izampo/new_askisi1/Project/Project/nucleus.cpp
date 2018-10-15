#include "nucleus.h"
#include<iostream>

nucleus::nucleus(int neu_num){	
	num = neu_num;
	total_charge = protons1.getTotal();
	pt = new neutron*[num];
	for (int i = 0; i < neu_num; i++){
		pt[i] =new neutron();
		total_charge += pt[i]->getTotal();
	}
	total_charge = protons2.getTotal() + protons3.getTotal() + protons4.getTotal() + protons5.getTotal() + protons6.getTotal();
	std::cout<<"a nucleus has been constructed"<<std::endl;
}

void nucleus::print(){
	for (int i = 0; i < num; i++){
		pt[i]->print();
	}
	protons1.print();
	protons2.print();
	protons3.print();
	protons4.print();
	protons5.print();
	protons6.print();
}
nucleus::~nucleus(){
	for (int i = 0; i < num; i++){
		delete pt[i];
	}
	delete[]pt;
	std::cout<<"a nucleus has been destroyed"<<std::endl;
}

int nucleus::total_electric_charge(){
	return total_charge;
}

