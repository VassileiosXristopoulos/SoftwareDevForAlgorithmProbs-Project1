#include "atom.h"
#include <iostream>

atom::atom(int number){
	atom **p=new atom*[number];
	 for(int i=0;i<number;i++){
	 p[i]=NULL;
	 }
}
atom::~atom(){
	//for(int i=0;i<number;i++){
	//	delete p[i];
//	}
	delete [] p;
}

