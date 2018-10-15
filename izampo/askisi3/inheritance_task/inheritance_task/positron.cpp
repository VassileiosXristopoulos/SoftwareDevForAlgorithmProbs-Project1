#include "positron.h"
#include <iostream>
using namespace std;
positron::positron() :fermion(0.510998946, 1, 0.5,"positron"){
	cout << "a positron has been constructed" << endl;
}
