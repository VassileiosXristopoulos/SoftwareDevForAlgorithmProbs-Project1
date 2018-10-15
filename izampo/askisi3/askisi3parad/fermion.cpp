#include "fermion.h"
#include <iostream>
#include <string>
using namespace std;

fermion::fermion(double massVar, double chargeVar, double spinVar,string my_id) :particle(massVar, chargeVar, spinVar,my_id), statistics("Fermi-Dirac"){
}
fermion::fermion(string my_id,double massVar, double spinVar, double chargeVar) : particle(my_id, massVar, spinVar,chargeVar), statistics("Fermi-Dirac"){
}
string& fermion::get_statistics(){
return statistics;
}
fermion::~fermion(){
}
