#include "antineutrino.h"
#include "neutrino.h"
#include "photon.h"
#include "proton.h"
#include "neutron.h"
#include "electron.h"
#include "positron.h"
#include "particle.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
int main(void){
	srand(time(NULL));
	
	int choose,counter;
	double total_charge;
	int N, M;
	cout << "give total particle number"<<endl;
	cin >> M;
	cout << "give N" << endl;;
	cin >> N;
	vector<particle*>my_array;
	int total_counter = 0;
	for (int i = 0; i < M; i++){
		choose = rand() % 7 + 1;
		if (choose == 1){
			my_array.push_back( new proton() );
		}
		else if (choose == 2){
			my_array.push_back( new neutron() );
		}
		else if (choose == 3){
			my_array.push_back( new electron() );
		}
		else if (choose == 4){
			my_array.push_back(new positron() );
		}
		else if (choose == 5){
			my_array.push_back(new neutrino() );
		}
		else if (choose == 6){
			my_array.push_back(new antineutrino() );
		}
		else if(choose==7){
			my_array.push_back(new photon() );
		}
	}
		counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "proton"){
			counter++;
			total_counter++;
		}
	}
	cout << "protons are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "neutron"){
			counter++;
			total_counter++;
		}
	}
	cout << "neutrons are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "electron"){
			counter++;
			total_counter++;
		}
	}
	cout << "electrons are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "positron"){
			counter++;
			total_counter++;
		}
	}
	cout << "positrons are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "neutrino"){
			counter++;
			total_counter++;
		}
	}
	cout << "neutrinos are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "antineutrino"){
			counter++;
			total_counter++;
		}
	}
	cout << "antineutrinos are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "photon"){
			counter++;
			total_counter++;
		}
	}
	cout << "photons are:" << counter << endl;
	total_charge = 0;
	double total_mass=0;
	int total_spin=0;
	for (int i = 0; i < my_array.size(); i++){
		total_charge += my_array[i]->get_charge();
		total_mass+=my_array[i]->get_mass();
		total_spin+=my_array[i]->get_spin();
	}
	cout << "total charge is:" << total_charge << endl;

	for (int i = 0; i < N; i++){
		int constant = rand() % my_array.size() ;
		my_array[constant]->interactions(my_array, constant, my_array.size()-1);
	}
	//here starts
	int fermion_size=0;
	int boson_size=0;
	M = my_array.size();
	int total_counter2 = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "proton"){
			counter++;
			total_counter2++;
			fermion_size++;
		}
	}
	cout << "final protons are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "neutron"){
			counter++;
			total_counter2++;
			fermion_size++;

		}
	}
	cout << "final neutrons are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "electron"){
			counter++;
			total_counter2++;
			fermion_size++;

		}
	}
	cout << "final electrons are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "positron"){
			counter++;
			fermion_size++;
			total_counter2++;
		}
	}
	cout << "final positrons are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "neutrino"){
			counter++;
			total_counter2++;
			fermion_size++;

		}
	}
	cout << "final neutrinos are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "antineutrino"){
			counter++;
			total_counter2++;
			fermion_size++;

		}
	}
	cout << "final antineutrinos are:" << counter << endl;
	counter = 0;
	for (int i = 0; i < M; i++){
		if (my_array[i]->get_id() == "photon"){
			counter++;
			total_counter2++;
			boson_size++;
		}
	}
	cout << "final photons are:" << counter << endl;
	//here ends
	double metavoli = total_counter2 /(double) total_counter;
	cout << "metavoli:" << metavoli << endl;
	if (fermion_size > boson_size){
		cout << "living in material world" << endl;
	}
	else if (boson_size > fermion_size){
		cout << "radiation prevails" << endl;
	}
	else{
		cout << "equilibrium?" << endl;
	}
	double total_mass2=0;
	double total_spin2=0;
	double total_charge2 = 0;
	for (int i = 0; i < my_array.size(); i++){
		total_charge2 += my_array[i]->get_charge();
		total_mass2+=my_array[i]->get_mass();
		total_spin2+=my_array[i]->get_spin();
	}
	cout<<total_mass <<total_mass2<<endl;
	cout<<"sinoliki diafora mass: "<<total_mass-total_mass2<<endl;
	cout<<"sinoliki diafora spin: "<<total_spin-total_spin2<<endl;
	if( (total_mass2-total_mass!=0) || (total_spin2-total_spin!=0) ){
	cout<<"how it comes!"<<endl;
	}
	cout << "total charge2 is: " << total_charge2 << endl;
	if (total_charge2 == total_charge){
		cout << "conservation verified!" << endl;
	}
	else{//when its ok i delete this
		cout << "error" << endl;
	}
	cout << endl << "--------------" << endl;
	int final_size = my_array.size();
	for (int i = 0; i < final_size; i++){
		delete my_array[i];
	}
	
}


