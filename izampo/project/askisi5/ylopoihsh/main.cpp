#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <sstream>
using namespace std;
#include "trader.h"
#include "user.h"
#include "punter.h"
#include "director.h"
int wrapper(int reg){
#ifdef R 
	return 0; //willing to register
#else 
	reg = 0;
	return 1; //willing to log in
#endif
}
bool empty(ifstream &myfile){
	return myfile.peek() == std::ifstream::traits_type::eof();
}
int main(void){
	string type;
	string **pinakas;
	double my_balance;
	string myid;
	int random;
	string username;
	int reg=0;
	string full;
	string id, fullname, password, status, balance, freebets;
	srand((unsigned int) time(NULL));
	if (!wrapper(reg)){
		reg = 1;
		int found = 0;
	
		string thrash,data;
		ifstream my_file("users.txt");
		cout << "give username" << endl;
		std::cin >> username;
		
		while (my_file.good()){
			getline(my_file, thrash, '|');
			getline(my_file, data, '|');
			if (data == username){
				found = 1;
			}
			getline(my_file, thrash, '\n');
		}
		if (found == 0){
			ifstream newfile("users.txt");
			ofstream file("users.txt",ios::app);
			int result = empty(newfile);
			if (!result){ //check if file is empty
				file << "\n";
			}
			newfile.close();
			//file.seekp(0, ios::end);
			//file << username << "|";
			int count = 0;
			string password2;
			do{
				if (count != 0){
					cout << "passwords different!" << endl;
				}
				cout << "give password" << endl;
				std::cin >> password;
				cout << "give password again" << endl;
				std::cin >> password2;
				count++;
			} while (password != password2);
			//cout << "give fullname" << endl;
			string firstname,lastname;
			cout << "Enter Firstname" << endl;
			std::cin >> firstname;
			cout << "Enter Lastname" << endl;
			std::cin >> lastname;
			full.append(firstname);
			full.append(" ");
			full.append(lastname);
			
			if (result){
				myid = "1";
			}
			else{
				ifstream dfile("users.txt");
				string mydata;
				while (dfile.good()){
					getline(dfile, mydata, '\n');
				}//at the end mydata will have the last row
				string lastid = mydata.substr(0,1);
				int last_id = atoi(lastid.c_str());
				last_id++;
				stringstream s;
				s << last_id;
				string str = s.str();
				myid = str;
			}
			random = rand() % 3 + 1;//I HAVE NOT ADDED THE ID FIELD 
			file <<myid<<"|"<<username<<"|"<<full << "|"<<password << "|" << random<<"|"<<" "<<"|"<<" "<<"|"<<" "<<"|";
			my_file.close();
			file.close();
		}
		else{
			my_file.close();
			cout << "Sorry this name is not available" << endl;
			return 1;
		}
	}	
	string  pass,usern;
	cout << "Welcome to BetAdoroi" << endl;
	if (reg == 0){
		cout << "Please give your username and password or 'guest' to enter as a guest " << endl;
		std::cin >> usern;
		if (usern == "guest"){
			user user1;
			//int statement;
			string hi = user1.Home();
			user1.foo("guest");
			while (hi != "X"){
				if (hi == "H"){
					hi = user1.Home();
				}
				user1.print_choises(hi);
				hi = user1.navigate(hi);
			}
			user1.audit("Exit");
			return 0;
		}
		else{
			int my_id;
			//int found=0;
			string thrash, data, passw;
			ifstream cfile("users.txt");
			//		string data;
			int num = 0;
			while (cfile.good()){
				getline(cfile, data, '\n');
				num++;
			}//num has the size of file
			cfile.close();
			ifstream afile("users.txt");

			pinakas = new string*[num];
			for (int i = 0; i < num; i++){
				pinakas[i] = new string[8];
			}
			//		string data;
			for (int i = 0; i < num; i++){
				for (int j = 0; j < 6; j++){
					getline(afile, data, '|');
					pinakas[i][j] = data;
				}
				getline(afile, data, '\n');
				pinakas[i][7] = data;
			}
			int found = 0;
			int count = 0;

			//cin >> usern;
			while (found == 0){
				if (count != 0){
					cout << "wrong username" << endl;
					cin >> usern;
				}

				//string passw;
				for (int i = 0; i < num; i++){
					//getline(afile, data, '|');
					string myid = pinakas[i][0];
					my_id = atoi(myid.c_str());
					//getline(afile, data, '|');
					username = pinakas[i][1];
					fullname = pinakas[i][2];
					password = pinakas[i][3];
					type = pinakas[i][4];
					status = pinakas[i][5];
					string mine = status.substr(0, 1);
					if (mine == "L"){
						cout << "your account is locked" << endl;
						return 0;
					}
					balance = pinakas[i][6];
					freebets = pinakas[i][7];
					if (usern == username){
						found = 1;
						int counter = 0;
						do{
							if (counter != 0){
								cout << "wrong password" << endl;
								cin >> passw;
							}
							else{
								cin >> passw;
							}
							counter++;
						} while (passw != password);
						if (balance > "47"){
							//my_balance = atof(str.c_str(balance));
							my_balance = atof(balance.c_str());
						}
						else{
							my_balance = 0;
						}
						//ENTER PROGRAMM
						if (type == "1"){
							punter punter1(my_id, username, fullname, password, status, my_balance, freebets);
							punter1.Home();
							punter1.audit("Exit", "");
							return 0;
						}
						else if (type == "2"){
							trader trader1(my_id, username, fullname, password, status, my_balance, freebets);
							//trader1.Home();
							string hi = trader1.Home();
							//trader1.foo("guest");
							while (hi != "X"){
								if (hi == "H"){
									hi = trader1.Home();
								}
								trader1.print_choises(hi);
								hi = trader1.navigate(hi, "trader");
							}
							return 0;
						}
						else if (type == "3"){
							director director1(my_id, username, fullname, password, status, my_balance, freebets);
							director1.Home();
							return 0;
						}
					}
				}
				count++;
			}
			afile.close();

		}
	}
	else{
		int newid = atoi(myid.c_str());
		if (random == 1){
			punter punter1(newid, username, fullname, password, status, 0, freebets);
			punter1.Home();
			punter1.audit("Exit","");
			return 0;
		}
		else if (random == 2){
			trader trader1(newid, username, fullname, password, status, 0, freebets);
			//trader1.Home();
			string hi = trader1.Home();
			//trader1.foo("guest");
			while (hi != "X"){
				if (hi == "H"){
					hi = trader1.Home();
				}
				trader1.print_choises(hi);
				hi = trader1.navigate(hi, "trader");
			}
			return 0;
		}
		else if (random == 3){
			director director1(newid, username, fullname, password, status, 0, freebets);
			director1.Home();
			return 0;
		}
	}
	std::cin.clear();
	std::cin.ignore();
	std::cin.get();
}
