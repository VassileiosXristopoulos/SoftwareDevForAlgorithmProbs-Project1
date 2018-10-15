#include "nucleus.h"
#include "electron.h"
class atom{
	private:
	int mass_number;
	int atomic_number;
	int electric_charge;
	int total;
	int protons;
	int neutrons;
	nucleus nucleus1;
	electron electrons1;
	electron electrons2;
	electron electrons3;
	electron electrons4;
	electron electrons5;
	electron electrons6;
	public:
		atom(int,int atomic_number=6,int protons=6,int electric_charge=0);
		~atom();
		void print();
		int get_atom_number();
		int get_mass_number();
		int get_electric_charge();
		int total_electric_charge();
		int get_Protons();
		int get_Neutrons();
};

