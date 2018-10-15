#include <iostream>
#include "neutron.h"
using namespace std;
neutron::neutron() :fermion("neutron",939.56541, 0.5){
	cout << "a neutron has been constructed and its statistics is "<<get_statistics() << endl;
}
