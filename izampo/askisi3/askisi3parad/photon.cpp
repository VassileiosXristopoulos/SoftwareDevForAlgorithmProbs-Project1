#include "photon.h"
#include <iostream>
using namespace std;
photon::photon() :boson("photon",1){
	cout << "a photon has been contructed and its statistics is " <<get_statistics()<< endl;
}
