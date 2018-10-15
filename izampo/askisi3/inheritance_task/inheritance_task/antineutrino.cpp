#include "antineutrino.h"
#include <iostream>

using namespace std;
antineutrino::antineutrino() :fermion(0.320, 0.5, "antineutrino"){
	cout << "an antineutrino has been constructed" << endl;
}
