#include "fermion.h"
#include <iostream>
#include <string>
using namespace std;

fermion::fermion(double massVar, double chargeVar, double spinVar,string my_id) :particle(massVar, chargeVar, spinVar,my_id), statistics("Fermi-Dirac"){
}
fermion::fermion(double massVar, double spinVar,string my_id, double chargeVar) : particle(massVar, chargeVar, spinVar,my_id), statistics("Fermi-Dirac"){
}
fermion::~fermion(){
}
