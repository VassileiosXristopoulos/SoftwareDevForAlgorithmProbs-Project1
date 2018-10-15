#include "electron.h"
#include <iostream>
using namespace std;
electron::electron() :fermion(0.510998946, -1, 0.5,"electron"){
	cout << "an electron has been constructed" << endl;
}
