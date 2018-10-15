#include "boson.h"
#include <iostream>
#include <string>
using namespace std;
boson::boson(string  my_id,double spinVar, double massVar, double chargeVar) :particle(my_id,spinVar, massVar,chargeVar), statistics("Bose-Einstein"){

}
string& boson::get_statistics(){
return statistics;
}
boson::~boson(){
}
