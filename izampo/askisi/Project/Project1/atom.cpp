#include "atom.h"
#include <iostream>

atom::atom(int num,atom ***arr1,int i){
	number =num ;
	p = new atom*[num];
	if (num == 4){
		arr1[i] = p;
	}
}
atom::~atom(){
	for(int i=0;i<number;i++){
		delete p[i];
		}
	delete[] p;
}
