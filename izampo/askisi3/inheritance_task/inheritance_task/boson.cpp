#include "boson.h"
#include <iostream>
#include <string>
using namespace std;
boson::boson(int spinVar,string my_id, double massVar, double chargeVar) :particle(spinVar, massVar, chargeVar,my_id), statistics("Bose-Einstein"){

}
boson::~boson(){
}
