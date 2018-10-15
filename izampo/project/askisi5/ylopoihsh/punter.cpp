#include "punter.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

punter::punter(int myid, string u, string f, string p,string s = "-", double b = 0, string fr = "0")
	:username(u), fullname(f), password(p), type(1), status(s), id(myid){
	user::foo("non");
}
punter::~punter(){}

int punter::Home(){
	string hi = user::Home();
	string letter = navigate(hi);
	if (letter == "H"){
		audit("Home", "");
		Home();
	}
	else if (letter == "X"){
		return 0;
	}
	else if (letter == "T"){
		audit("Toggle", "");
	}

}
void punter::print_choises(string myid,string s){
	user::print_choises(myid,s);
	cout << "A(Account)" << endl;
	if (level == 5){
		cout << "Place(Place)" << endl;
	}
}
string punter::navigate(string myid,string s){
	print_choises(myid,s);
	string num = user::navigate(myid, "subclass!");
	if (num == "H"){
		audit("Home", "");
		num = Home();
		if(num=="H"){
		audit("Home","");
		return "H";
		}
		else if(num=="X"){
		return "X";
	  //  exit(0);
		}
	}
	else if (num == "T"){
		audit("Toggle", "");
		string letter = navigate(myid,"T");
		if (letter == "H"){
			audit("Home","");
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "A"){
		audit("Account", "");
		Account();
		string letter = navigate(myid);
		if (letter == "H"){
			audit("Home","");
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "Place"){
		Place();
		string letter = navigate(myid);
		if (letter == "H"){
			audit("Home","");
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "X"){
		//EXIT PROGRAMM
		return "X";
	}
	else{
		// user::navigate returns id in num in this case
		string letter = navigate(num);
		if (letter == "H"){
			audit("Home","");
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
}
void punter::Account(){
	cout << "Welcome to your account!" << endl;
	cout << "Choose which node you want to visit" << endl;
	cout << "R (Rename)" << endl;
	cout << "P (Password)" << endl;
	cout << "B (Bets)" << endl;
	cout << "D (Deposit)" << endl;
	string myid;
	cin >> myid;
	if (myid == "R"){
		Rename();
	}
	else if (myid == "P"){
		Password();
	}
	else if (myid == "B"){
		audit("Bets", "");
		Bets();
	}
	else if (myid == "D"){
		Deposit();
	}
	else{
		cout<<"Your account doesn't incude this choise!Go back to the menu"<<endl;
		Home();
	}
}
void punter::Bets(){
	ifstream file("bets.txt");
	string my_id, data, betid, thrash;
	int myid;
	while (file.good()){
		getline(file, betid, '|');//bet id
		getline(file, my_id, '|');//user id
		//myid = stoi(my_id);
		myid = atoi(my_id.c_str());
		if (myid == id){
			getline(file, data, '|');//axristo
			getline(file, data, '|');//axristo
			getline(file, data, '|');//apotelesma
			cout << betid << " " << data << endl;;
		}
		getline(file, thrash, '\n');
	}
	file.close();
}

void punter::Rename(){
	int found;
	int count = 0;
	string new_username;
	//string id;
	string stuff;


	ifstream file;
	string thrash;
	do{
		file.open("users.txt");
		found = 0;
		cout << "Which username would you prefer?" << endl;
		cin >> new_username;
		while (file.good()){
			getline(file, thrash, '|');
			getline(file, stuff, '|');
			if (stuff == new_username){
				cout << "This username is already being used!Try an other one!" << endl;
				found = 1;
				file.close();
			}
		}
	} while (found == 1);
	file.close();

	string first;
	string kati;

	string third;
	ifstream my_file("users.txt");

	while (my_file.good()){
		getline(my_file, kati, '|');
		int num;
		num = atoi(kati.c_str());
		if (num == id){
			first.append(kati);
			first.append("|");
			getline(file, thrash, '|');
			break;
		}
		else{
			getline(my_file, thrash, '\n');
		}
	}int counter = 0;
	while (my_file.good()){
		if (counter == 0){
			getline(my_file, thrash, '|');
		}
		getline(my_file, thrash, '\n');
		third = third.append(thrash);
		third.append("\n");
		counter++;
	}
	my_file.close();

	first.append(new_username);
	first.append("|");
	third=third.substr(0,third.size()-1);
	first.append(third);
	ofstream myfile("users.txt");
	myfile << first;
	myfile.close();
	cout << "username succesfully changed!" << endl;
	audit("Rename", new_username);
}
void punter::Password(){
	cout << "Seems like you want to change your password!" << endl;
	cout << "Enter your old password,please" << endl;
	int counter = 0;
	while (counter<2){
		string pswd;
		cin >> pswd;
		ifstream file("users.txt");
		string thrash, myid, oldpsw;
		int check, found = 0;
		int loops = 0;
		while (file.good() && found == 0){
			if (++loops == 1){
				getline(file, myid, '|');
				check = atoi(myid.c_str());
			}
			if (id == check){
				found = 1;
				for (int i = 0; i<2; i++){
					getline(file, thrash, '|');
				}
				getline(file, oldpsw, '|');
				if (oldpsw == password){
					cout << "Now please,re-enter your old password" << endl;
					counter++;
				}
				else{
					cout << "You missed something!Try again,please" << endl;
					counter--;
				}
			}
			else{
				getline(file, thrash, '\n');
				getline(file, myid, '|');
				check = atoi(myid.c_str());
			}
		}
		file.close();
	}
	cout << "Great!Now enter the new password" << endl;
	string new_password;
	cin >> new_password;
	string thrash, first, third;
	ifstream file("users.txt");
	int complete = 0;
	while (file.good() && (complete == 0)){
		getline(file, thrash, '|');
		int n;
		n = atoi(thrash.c_str());
		if (n == id){
			first.append(thrash);
			first.append("|");
			for (int i = 0; i<2; i++){
				string kati_allo;
				getline(file, kati_allo, '|');
				first.append(kati_allo);
				first.append("|");
			}
			getline(file, thrash, '|');
			while (file.good()){
				string kati;
				getline(file, kati, '\n');
				third.append(kati);
				third.append("\n");
				complete = 1;
			}
		}
		else{
			string kati;
			getline(file, kati, '\n');
			first.append(kati);
			first.append("\n");
		}
	}
	file.close();
	first.append(new_password);
	first.append("|");
	third=third.substr(0,third.size()-1);
	first.append(third);
	ofstream myfile("users.txt");
	myfile << first;
	myfile.close();
	audit("Password", "");
}

void punter::Place(){
	ifstream file("users.txt");
	string myid, thrash, data, freebets;
	vector<char>let_vector;
	vector<string>my_vector;
	vector<string>final_vector;
	string smoney;
	string letters;
	int my_id;
	int money;
	double final_money;
	string choise;
	while (file.good()){
		getline(file, myid, '|');
		if (myid == " "){
			my_id = 0;
		}
		else{
			my_id = atoi(myid.c_str());
		}
		if (my_id == id){
			for (int i = 0; i < 6; i++){
				getline(file, data, '|');
			}
			getline(file, freebets, '|'); //pairnw to freebets
			cout << "Your balance is: " << data << endl;//emfanizw to upoloipo tou logariasmou
		}
		getline(file, thrash, '\n');
	}
	cout << "Please give your choise" << endl;
	cin >> choise;
	if (choise == "cancel"){
		return;
	}
	else{
		int keeper = 0; //for the last komma
		int size = freebets.size();
		string copy = freebets;
		for (unsigned int i = 0; i < freebets.size(); i++){
			if (freebets[i] == ','){
				string s = freebets.substr(keeper, i - keeper); //set breakpoint
				copy = copy.substr(i - keeper + 1); 
				keeper += i;
				keeper++;
				my_vector.push_back(s);
			}
		}
		string s = copy.substr(0);
		my_vector.push_back(s);
		char s1 = 'A';

		cout << "Your available freebets are:" << endl;
		for (unsigned int i = 0; i < my_vector.size(); i++){
			cout << s1 << ". " << my_vector[i] << endl;
			let_vector.push_back(s1);
			s1 = s1 + 1;
		}
	}
	string amount;
	cout << "please give the amount of money you want to deposit" << endl;
	cin >> amount;
	int found = 0;
	if (amount < "A"){
		double money;
		money = atof(amount.c_str());
		ifstream my_file("users.txt");
		string first, second, third;
		while (my_file.good()){
			string data, thrash;
			getline(my_file, data, '|');
			int mdata;
			mdata = atoi(data.c_str());
			if ((mdata == id) && (found == 0)){
				first.append(data);
				first.append("|");
				for (unsigned int i = 0; i < 5; i++){
					string thrash;
					getline(my_file, thrash, '|');
					first.append(thrash);
					first.append("|");
				}
				string old_amount;
				getline(my_file, old_amount, '|');
				if (old_amount == " "){
					cout << "please fill your wallet first" << endl;
					audit("Place", "No money at all");
					return;
				}
				else{
					double myamount=atof(old_amount.c_str());
					int count = 0;
					do{
						if (count != 0){
							cout << "please bet smaller price" << endl;
							audit("Place", "Not enough money");
							cin >> money;
						}
					} while (money > myamount);
					found = 1;
					int new_money;
					if (count > 1){
						stringstream s2;
						s2 << money;
						amount = s2.str();
					}
					int new_amount;
					final_money = myamount - money;
					stringstream s1;
					s1 << final_money;
					smoney = s1.str(); //smoney have the new money
					string free;
					getline(my_file, free, '\n');
					third.append(free);
					third.append("\n");
					//here i am ok and i should refresh the balance on users and place to the bets file
				}
			}
			else{
				if (found == 0){
					first.append(data);
					first.append("|");
					string thrash;
					getline(my_file, thrash, '\n');
					first.append(thrash);
					first.append("\n");//go to next line
				}
				else{
					third.append(data);
					third.append("|");
					string free;
					getline(my_file, free, '\n');
					third.append(free);
					third.append("\n");
				}
			}
		}
		my_file.close();
		first.append(smoney);
		first.append("|");
		third=third.substr(0,third.size()-1);
		first.append(third);
		ofstream file("users.txt");
		file << first;
		file.close(); //I REFRESHED THE USERS FILE, TIME TO PLACE THE BET
		string data2, thrash;
		ifstream afile("bets.txt");
		while (afile.good()){
			getline(afile, data2, '|');
			getline(afile, thrash, '\n');
		}
		afile.close();
		int mynum = atoi(data2.c_str());
		mynum++;
		stringstream s1;
		s1 << mynum;
		string my_betid = s1.str();//my_betid has the bet id
		stringstream s;
		s << id;
		string my_userid = s.str(); //my_userid has the user id 
		string mynode = fourth_level;
		mynode.append("."); //new_amount has the stake
		mynode.append(choise); //mynode has the node id
		ofstream bfile("bets.txt",ios::app);
		//file.seekp(0, ios::end);
		ifstream nefile("bets.txt");
		if (!empty(nefile)){
			bfile << "\n";
		}
		nefile.close();
 		string data1;
		//////////////////////////
		data1 = "from his deposit:/";
		data1.append(mynode);
		data1.append("/");
		data1.append(amount);
		audit("Place", data1);
		/////////////////////////
		string put;
		put.append(my_betid);
		put.append("|");
		put.append(my_userid);
		put.append("|");
		put.append(mynode);
		put.append("|");
		put.append(amount);
		put.append("|-|");
		bfile << put;
		bfile.close();
	}
	else{
		const char *cstr = amount.c_str();
			string my_ctsr(amount);
		int keeper;
		for (unsigned int i = 0; i < my_vector.size(); i++){
			if ((let_vector[i]) == (*cstr)){
				keeper = i;
			}
		}
		for (unsigned int i = 0; i < my_vector.size(); i++){
			if (i != keeper){
				final_vector.push_back(my_vector[i]);
			}
		}
		//here final_vector has all the remaining freebets
		ifstream my_file("users.txt");
		string first, second, third;
		int found = 0;
		while (my_file.good()){
			string data, thrash;
			getline(my_file, data, '|');
			int mdata;
			mdata = atoi(data.c_str());
			if (mdata == id){
				found = 1;
				first.append(data);
				first.append("|");
				for (int i = 0; i < 6; i++){
					getline(my_file, thrash, '|');
					first.append(thrash);
					first.append("|");
				}
				getline(my_file, thrash, '\n');
				for (unsigned int i = 0; i < final_vector.size(); i++){
					if (i != (final_vector.size() - 1)){
						second.append(final_vector[i]);
						second.append(",");
					}
					else{
						second.append(final_vector[i]);
					}
				}
				while (file.good()){
					string mine;
					getline(my_file, mine, '\n');
					third.append(mine);
					third.append("\n");
				}
			}
			else{
				if (found == 0){
					string ok;
					getline(my_file, ok, '\n');
					first.append(ok);
					first.append("\n");
				}
				else{
					third.append(data);
					third.append("|");
					string ok;
					getline(my_file, ok, '\n');
					third.append(ok);
					third.append("\n");
				}
			}
		}
		second.append("|\n");
		first.append(second);
		third=third.substr(0,third.size()-1);
		first.append(third);
		my_file.close();
		ofstream afile("users.txt");
		afile << first;
		afile.close();//FINISHED THE PROJECT OF UPGRADING FREEBETS TO FILE


		ifstream file("bets.txt");
		string data, thrash;
		while (file.good()){
			getline(file, data, '|');
			getline(file, thrash, '\n');
		}
		//my_vector[keeper] has the stake
		int mynum = atoi(data.c_str());
		mynum++;
		stringstream s1;
		s1 << mynum;
		string my_betid = s1.str();//my_betid has the bet id
		stringstream s;
		s << id;
		string my_userid = s.str(); //my_userid has the user id 
		string mynode = fourth_level;
		mynode.append(".");
		mynode.append(choise); //mynode has the node id
		file.close();
		ofstream bfile("bets.txt",ios::app);
		bfile<<"\n";
		string whole;
		whole.append(my_betid);
		whole.append("|");
		whole.append(my_userid);
		whole.append("|");
		whole.append(mynode);
		whole.append("|");
		whole.append(my_vector[keeper]);
		whole.append("|-|");
		bfile << whole;
		bfile.close();
	    data = "from freebets:/";
		data.append(mynode);
		data.append("/");
		data.append(my_vector[keeper]);
		audit("Place", data);
	}
}

void punter::Deposit(){
	cout << "Please enter the amount of money you want to add to your account" << endl;
	double dep;
	cin >> dep;
	string thrash, first, third, money;
	ifstream file("users.txt");
	int complete = 0;
	double old_dep;
	while (file.good() && (complete == 0)){
		getline(file, thrash, '|');
		int n;
		n = atoi(thrash.c_str());
		if (n == id){
			first.append(thrash);
			first.append("|");
			for (int i = 0; i<5; i++){
				string kati_allo;
				getline(file, kati_allo, '|');
				first.append(kati_allo);
				first.append("|");
			}
			getline(file, money, '|');
			if (money == " "){
				old_dep = 0;
			}
			else{
				old_dep = atof(money.c_str());
			}
			while (file.good()){
				string kati;
				getline(file, kati, '\n');
				third.append(kati);
				third.append("\n");
				complete = 1;
			}
		}
		else{
			string kati;
			getline(file, kati, '\n');
			first.append(kati);
			first.append("\n");
		}
	}
	file.close();
	double sum;
	sum = old_dep + dep;
	stringstream s;
	s << sum;
	string s5 = s.str();
	first.append(s5);
	first.append("|");
	third=third.substr(0,third.size()-1);
	first.append(third);
	ofstream myfile("users.txt");
	myfile << first;
	myfile.close();
	stringstream dep1;
	dep1 << dep;
	string s6 = dep1.str();
	audit("Deposit", s6);
}

void punter::audit(string action_name, string data){
	ofstream file("audit.txt",ios::app);
	ifstream nefile("audit.txt");
	if (!empty(nefile)){
		file << "\n";
	}
	nefile.close();
	string thrash;
	thrash.append(username);
	thrash.append("|");
	thrash.append(action_name);
	thrash.append("|");
	if (data != ""){
		thrash.append(data);
		thrash.append("|");
	}
	thrash=thrash.substr(0,thrash.size()-1);
	file << thrash;
	file.close();
}
bool punter::empty(ifstream &myfile){
	return myfile.peek() == std::ifstream::traits_type::eof();
}
