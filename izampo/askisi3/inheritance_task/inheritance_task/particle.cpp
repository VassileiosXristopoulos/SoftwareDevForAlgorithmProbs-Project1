#include <iostream>
#include <string>
#include "particle.h"
#include "antineutrino.h"
#include "neutrino.h"
#include "photon.h"
#include "proton.h"
#include "neutron.h"
#include "electron.h"
#include "positron.h"
using namespace std;
particle::particle(double massVar, double chargeVar, double spinVar,string& my_id){
	mass = massVar;
	spin = spinVar;
	electric_charge = chargeVar;
	id = my_id;
}
particle::particle(double massVar, double chargeVar, double spinVar, string& my_id){
	mass = massVar;
	spin = spinVar;
	electric_charge = chargeVar;
	id = my_id;
}
string& particle::get_id(){
	return id;
}
double particle::get_charge(){
	return electric_charge;
}
double particle::get_mass(){
    return mass;
 }
double particle::get_spin(){
    return spin;
   }  
 particle::~particle(){
}
 void particle::interactions(vector<particle*>&my_array, int position, int end){
	 if (position == 0){
		 if (my_array[position]->id == "proton"){
			 if (my_array[position + 1]->id == "antineutrino"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new neutron();
				 my_array[position + 1] = new positron();
			 }
			 else if (my_array[position + 1]->id == "electron"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new neutron();
				 my_array[position + 1] = new neutrino();
			 }
			 else{
			 delete my_array[position];
				 my_array[position] = new neutron();
				 vector<particle*>new_vector;
				 for (int i = 0; i <= position; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 new_vector.push_back(new positron());
				 new_vector.push_back(new neutrino());
				 for (int i = position + 3; i < end; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 my_array.resize(new_vector.size());
				 for (int i = 0; i < my_array.size(); i++){
					 my_array.at(i) = new_vector.at(i);
				 }
			 }
		 }
		 else if (my_array[position]->id == "neutron"){
			 if (my_array[position + 1]->id == "neutrino"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new proton();
				 my_array[position + 1] = new electron();
			 }
			 else{
			 	 delete my_array[position];
				 my_array[position] = new proton();
				 vector<particle*>new_vector;
				 for (int i = 0; i <= position; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 new_vector.push_back(new electron());
				 new_vector.push_back(new antineutrino());
				 for (int i = position + 3; i < end; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 my_array.resize(new_vector.size());
				 for (int i = 0; i < my_array.size(); i++){
					 my_array.at(i) = new_vector.at(i);
				 }
			 }
		 }
		 else if (my_array[position]->id == "electron"){
			 if (my_array[position + 1]->id == "positron"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new photon();
				 my_array[position + 1] = new photon();

			 }
			 else if (my_array[position + 1]->id == "proton"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new neutron();
				 my_array[position + 1] = new neutrino();
			 }

		 }
		 else if (my_array[position]->id == "photon"){
			 if (my_array[position + 1]->id == "photon"){
			 delete my_array[position];
			 delete my_array[position+1];
				 my_array[position] = new electron();
				 my_array[position + 1] = new positron();
			 }
		 }
		 else if (my_array[position]->id == "antineutrino"){
			 if (my_array[position + 1]->id == "proton"){
			 delete my_array[position];
			 delete my_array[position+1];
				 my_array[position] = new neutron();
				 my_array[position + 1] = new positron();
			 }
		 }
		 else if (my_array[position]->id == "neutrino"){
			 if (my_array[position + 1]->id == "neutron"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new proton();
				 my_array[position + 1] = new electron();
			 }
		 }
		 else if (my_array[position]->id == "positron"){
			 if (my_array[position + 1]->id == "electron"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new photon();
				 my_array[position + 1] = new photon();
			 }
		 }
	 }
	 else if (position == end){
		 if (my_array[position]->id == "proton"){
			 if (my_array[position - 1]->id == "antineutrino"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new positron();
			 }
			 else if (my_array[position - 1]->id == "electron"){
			 delete my_array[position];
			 delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new neutrino();
			 }
			 else{
			    delete my_array[position];
				 my_array[position] = new neutron();
				 vector<particle*>new_vector;
				 for (int i = 0; i <= position; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 new_vector.push_back(new positron());
				 new_vector.push_back(new neutrino());
				 for (int i = position + 3; i < end; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 my_array.resize(new_vector.size());
				 for (int i = 0; i < my_array.size(); i++){
					 my_array.at(i) = new_vector.at(i);
				 }
			 }
		 }
		 else if (my_array[position]->id == "neutron"){
			 if (my_array[position - 1]->id == "neutrino"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new proton();
				 my_array[position - 1] = new electron();
			 }
			 else{
			    delete my_array[position];
				 my_array[position] = new proton();
				 vector<particle*>new_vector;
				 for (int i = 0; i <= position; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 new_vector.push_back(new electron());
				 new_vector.push_back(new antineutrino());
				 for (int i = position + 3; i < end; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 my_array.resize(new_vector.size());
				 for (int i = 0; i < my_array.size(); i++){
					 my_array.at(i) = new_vector.at(i);
				 }
			 }
		 }
		 else if (my_array[position]->id == "electron"){
			 if (my_array[position - 1]->id == "positron"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new photon();
				 my_array[position - 1] = new photon();

			 }
			 else if (my_array[position - 1]->id == "proton"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new neutrino();
			 }

		 }
		 else if (my_array[position]->id == "photon"){
			 if (my_array[position - 1]->id == "photon"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new electron();
				 my_array[position - 1] = new positron();
			 }
		 }
		 else if (my_array[position]->id == "antineutrino"){
			 if (my_array[position - 1]->id == "proton"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new positron();
			 }
		 }
		 else if (my_array[position]->id == "neutrino"){
			 if (my_array[position - 1]->id == "neutron"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new proton();
				 my_array[position - 1] = new electron();
			 }
		 }
		 else if (my_array[position]->id == "positron"){
			 if (my_array[position - 1]->id == "electron"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new photon();
				 my_array[position - 1] = new photon();
			 }
		 }
	 }
	 else{
		 if (my_array[position]->id == "proton"){
			 if (my_array[position - 1]->id == "antineutrino"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new positron();
			 }
			 else if (my_array[position + 1]->id == "electron"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new neutrino();
			 }
			 else if (my_array[position + 1]->id == "antineutrino"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new neutron();
				 my_array[position + 1] = new positron();
			 }
			 else if (my_array[position + 1]->id == "electron"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new neutron();
				 my_array[position + 1] = new neutrino();
			 }
			 else{
			    delete my_array[position];
				 my_array[position] = new neutron();
				 vector<particle*>new_vector;
				 for (int i = 0; i <= position; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 new_vector.push_back(new positron());
				 new_vector.push_back(new neutrino());
				 for (int i = position + 3; i < end; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 my_array.resize(new_vector.size());
				 for (int i = 0; i < my_array.size(); i++){
					 my_array.at(i) = new_vector.at(i);
				 }
			 }
		 }
		 else if (my_array[position]->id == "neutron"){
			 if (my_array[position - 1]->id == "neutrino"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new proton();
				 my_array[position - 1] = new electron();
			 }
			 else if (my_array[position + 1]->id == "neutrino"){
			 delete my_array[position];
			 delete my_array[position+1];
				 my_array[position] = new proton();
				 my_array[position + 1] = new electron();
			 }
			 else{
			    delete my_array[position];
				 my_array[position] = new proton();
				 vector<particle*>new_vector;
				 for (int i = 0; i <= position; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 new_vector.push_back(new electron());
				 new_vector.push_back(new antineutrino());
				 for (int i = position +3; i < end; i++){
					 new_vector.push_back(my_array.at(i));
				 }
				 my_array.resize(new_vector.size());
				 for (int i = 0; i < my_array.size(); i++){
					 my_array.at(i) = new_vector.at(i);
				 }
			 }
		 }
		 else if (my_array[position + 1]->id == "electron"){//here
			 if (my_array[position - 1]->id == "positron"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new photon();
				 my_array[position - 1] = new photon();

			 }
			 else if (my_array[position - 1]->id == "proton"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new neutrino();
			 }
			 else if (my_array[position + 1]->id == "positron"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new photon();
				 my_array[position - 1] = new photon();

			 }
			 else if (my_array[position + 1]->id == "proton"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new neutrino();
			 }
		 }
		 else if (my_array[position]->id == "photon"){
			 if (my_array[position - 1]->id == "photon"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new electron();
				 my_array[position - 1] = new positron();
			 }
			 else if (my_array[position + 1]->id == "photon"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new electron();
				 my_array[position + 1] = new positron();
			 }
		 }
		 else if (my_array[position]->id == "antineutrino"){
			 if (my_array[position - 1]->id == "proton"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new neutron();
				 my_array[position - 1] = new positron();
			 }
			 else if (my_array[position + 1]->id == "proton"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new neutron();
				 my_array[position + 1] = new positron();
			 }
		 }
		 else if (my_array[position]->id == "neutrino"){
			 if (my_array[position - 1]->id == "neutron"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new proton();
				 my_array[position - 1] = new electron();
			 }
			 else if (my_array[position + 1]->id == "neutron"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new proton();
				 my_array[position + 1] = new electron();
			 }
		 }
		 else if (my_array[position]->id == "positron"){
			 if (my_array[position + 1]->id == "electron"){
			    delete my_array[position];
			    delete my_array[position+1];
				 my_array[position] = new photon();
				 my_array[position + 1] = new photon();
			 }
			 else if (my_array[position - 1]->id == "electron"){
			    delete my_array[position];
			    delete my_array[position-1];
				 my_array[position] = new photon();
				 my_array[position - 1] = new photon();
			 }
		 }
	 }
 }
