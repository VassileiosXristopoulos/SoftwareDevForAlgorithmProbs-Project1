#include <iostream>
#include <ctime>
#include<cstdlib>
#include "atom.h"
using namespace std;

int main(void){
srand(time(NULL));
int number;
int a;
int total_protons=0;
int total_neutrons=0;
int totalElectricCharge=0;
		
		number = rand() % 10;
		
		//number=C.number();
		while(number>0){
		a = rand() % 3 + 6;
		atom C(a);
		C.print();
		totalElectricCharge=totalElectricCharge+C.total_electric_charge();
		total_protons=total_protons+C.get_Protons();
		total_neutrons=total_neutrons+C.get_Neutrons();
		number--;
		}
	cout<<"total protons are:"<<total_protons<<endl;
	cout<<"total neutrons are:"<<total_neutrons<<endl;
	cout<<"total electric charge is:"<<totalElectricCharge<<endl;
	cin.clear();
	cin.ignore();
	cin.get();
}

