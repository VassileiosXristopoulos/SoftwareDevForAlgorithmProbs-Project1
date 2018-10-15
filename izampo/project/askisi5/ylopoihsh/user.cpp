#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "user.h"
user::user() :path("Location:/BetAdoroi/"),level(1){}
user::~user(){}
bool user::empty(ifstream &myfile){
	return myfile.peek() == std::ifstream::traits_type::eof();
}
string user::Home(){
	if(able==1){
		audit("Home");
	}
	path = "Location:/BetAdoroi";
	nodes_level = "";
	cout << path << endl;
	ifstream file("hierarcy.txt");
	string data, id;
	int keeper = -1;
	while (file.good()){
		std::getline(file, data, ' ');
		keeper = data.size();
		if ((++keeper) == 3){
			string data2;
			std::getline(file, data2, '\n');
			cout << data[0] << ". " << data2 << endl;
		}
		else{
			string thrash;
			std::getline(file, thrash, '\n');
		}
	}
	cout << "which node you want to visit?" << endl;
	cin >> id; //give which node you want to go to 
	if (id == "H"){
		if(able==1){
			audit("Home");
		}
		return "H";
	}
	else if (id == "T"){
	 	//audit("Toggle");
		Toggle(path);
		return "T";
	}
	else if (id == "X"){
		return "X"; //EXIT PROGRAMM
	}
	file.close();

	ifstream my_file("hierarcy.txt");
	string id2 = id;
	id2.append(".");
	while (my_file.good()){
		string thrash;
		std::getline(my_file, thrash, ' ');
		if (thrash == id2){
			string data;
			std::getline(my_file, data, '\n');
			data=data.substr(0,data.size()-1);
			path.append("/");
			path.append(data);
		}
		std::getline(my_file, thrash, '\n');
	}
	level++;
	return id;
}

void user::foo(string usr){
	if(usr=="guest"){
		able=1;
	}
	else{
		able=0;
	}
}

void user::print_choises(string id,string l){
	cout << path << endl;
	if ((l != "T")&&(l!="no")){
		print_nodes(id, l);
	}
	cout << "Choose which node you want to visit" << endl;
	cout << "H(Home)" << endl;
	if (level == 5){
		cout << "T(Toggle)" << endl;
	}
	cout << "X(Exit)" << endl;
}
string user::navigate(string id,string op,string l){
	string my_id;
	if ((op=="none")&& (level > 2)){
		print_choises(id,l);
	}
	std::cin >> my_id;
	if (my_id == "H"){
		level--;
		return "H";
	}
	else if (my_id == "T"){
		Toggle(id);
		return "T";
	}
	else if (my_id == "X"){
		return "X"; //EXIT PROGRAMM
	}
	else if( my_id <"A" ){
		level++;
		id = id.append(".");
		id = id.append(my_id);
		if(level==5){
			fourth_level=id;
		}
		nodes_level = id;
		ifstream file("hierarcy.txt");
		while (file.good()){
			string thrash;
			std::getline(file, thrash, ' ');
			if (thrash == id){
				string data;
				std::getline(file, data, '\n');
				data=data.substr(0,data.size()-1);
				path.append(data);
				path.append("/");
			}
			std::getline(file, thrash, '\n');
		}
		file.close();
		if (op == "subclass!"){
			return id;
		}
		string letter=navigate(id,l);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
		else if (letter == "T"){
			print_choises(id, "no");
			string letter = navigate(id,"hi");
			if (letter == "H"){
				return "H";
			}
			else if (letter == "X"){
				return "X";
			}
		}
	} // I should check if this is the last node
	else{
		return my_id;
	}

}
void user::print_nodes(string id,string l){
	int convertion; // I convert variable "level" to how many positions right space should be
	if (level == 1){
		convertion = 3;
	}
	else if (level == 2){
		convertion = 4;
	}
	else if (level == 3){
		convertion = 6;
	}
	else if (level == 4){
		convertion = 8;
	}
	else{
		convertion = 10;
	}
	ifstream file("hierarcy.txt");
	string data, data3,data4;
	int keeper = -1;
	while (file.good()){
		std::getline(file, data, ' ');
		keeper = data.size();
		getline(file, data3, '\n');
		data4 = data3;
		data3 = data3.substr(0, 3);
		if (data3 == "[H]"){
			if (l=="director"){
				if ((++keeper) == convertion){ // I suppose i found the right level, i should find the right id 
					string data2;
					for (unsigned int i = 0; i<data.size() - 2; i++){ //example: if from file found 1.2.3 I covert to 1.2 to compare with given id
						data2.push_back(data[i]);
					}
					if (data2 == id){
						cout << data[data.length() - 1] << ". " << data4 << endl;
					}
				}
			}
			else{
				//return;
				string thrash, thrash1;
				do{
					getline(file, thrash, ' ');
					getline(file, thrash1, '\n');
					thrash = thrash.substr(0, data3.size()-2);
				} while (thrash == data4);
			}
		}
		else{
			if ((++keeper) == convertion){ // I suppose i found the right level, i should find the right id 
				string data8 = data;
				data = data.substr(0, data.size() - 2);
				if (data == id){
					cout << data8[data8.length() - 1] << ". " << data4 << endl;
				}
			}
		}

	}

	file.close();
}
void user::Toggle(string id){
	if (able == 1){
		audit("Toggle");
	}
	ifstream infile("hierarcy.txt");
	while (infile.good()){
		string id_stuff;
		int flag;
		int count = 1;
		do{
			getline(infile, id_stuff, ' ');
			flag = 0;
			id_stuff = id_stuff.substr(0, 7);
			if (id_stuff == id){
				flag = 1;
				string thrash,stuff;
				if (count == 1){
					getline(infile, thrash, '\n');
					getline(infile, thrash, ' ');
				}
				getline(infile, stuff, '#');
				cout << count <<". " << stuff;//ektypwnei oti vrei mexri thn diaish 
				count++;
				double dec = 1.0;
				int first_num, second_num;
				string f_num, s_num;
				getline(infile, f_num, '/');
				getline(infile, s_num, '\n');
				first_num = atoi(f_num.c_str());//arithmitis
				second_num = atoi(s_num.c_str());//paranomasths
				dec += (double)first_num / second_num;//dekadikos
				double y = 100 * dec;
				int rounded = (int)(y + 0.5);
				cout << "#" <<(rounded / 100)<<"."<<(rounded % 100);
			}
			if (flag == 0){
				getline(infile, id_stuff, '\n');
			}
			if (flag == 1){
				cout << endl;
			}
		} while (flag == 1);

	}
}

void user::audit(string action_name){
	ofstream file("audit.txt",ios::app);
	ifstream nefile("audit.txt");
	if (!empty(nefile)){
		file << "\n";
	}
	string thrash;
	thrash.append("guest");
	thrash.append("|");
	thrash.append(action_name);
	thrash.append("|");
	file << thrash;
	file.close();
}
