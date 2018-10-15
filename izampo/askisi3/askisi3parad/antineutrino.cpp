#include "antineutrino.h"
#include <iostream>

using namespace std;
antineutrino::antineutrino() :fermion("antineutrino",0.320, 0.5){
	cout << "an antineutrino has been constructed and its statistics is "<<get_statistics() << endl;
}
