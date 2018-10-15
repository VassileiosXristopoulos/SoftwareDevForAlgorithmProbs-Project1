#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
#include "director.h"
#include "trader.h"
director::director(int myid, string u, string f, string p, string s = "-", double b = 0, string fr = "0"):trader(myid,u,f,p,s,b,fr){}
director::~director(){}
int director::Home(){
	string hi = trader::Home();
	string letter = navigate(hi);
	if (letter == "H"){
		Home();
	}
	else if (letter == "T"){
		audit("Toggle","");
	}
	else if (letter == "X"){
		return 0;
	}
}
void director::print_choises(string id){
	trader::print_choises(id,"director");
	//cout << "S(Save)" << endl;
	cout << "L(Logs)" << endl;
	cout << "Visibility(Visibility)" << endl;
	cout << "R(Rename)" << endl;
	cout << "N(New)" << endl;
	cout << "C(Copy)" << endl;
	cout << "D(Delete)" << endl;
	cout << "U(Users)" << endl;
	//string num = trader::navigate(id);
}
string director::navigate(string id){
	print_choises(id);
	string num = trader::navigate(id,"director");
	if (num == "H"){
		//audit("Home","");
		return "H";
		//num = Home();
	}
	else if (num == "T"){
		return "T";
	}
	else if (num == "B"){
		trader::audit("Bets", "");
		Bets();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "L"){
		trader::audit("Logs", "");
		Logs();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "R"){
		Rename();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "Visibility"){
		Visibility();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "U"){
		//ts();
		trader::audit("Users","");
		Users();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "N"){
		//Freebets();
		New();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "V"){
		Void();
		//New();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "F"){
		Freebets();
		//New();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "S"){
		Settle();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "C"){
		Copy();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "D"){
		Delete();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "V"){
	//	Void();
		string letter = navigate(id);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "X"){
		//EXIT PROGRAMM
		//audit("Exit","");
		return "X";
	}
	else{
		// user::navigate returns id in num in this case
		string letter = navigate(num);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
}
void director::Logs(){
	ifstream myfile("audit.txt");
	int count = 0, no_care;
	string kati;
	getline(myfile, kati, '\n'); //because we have error with 1st line blank
	while (myfile.good()){
		string thrash;
		getline(myfile, thrash, '\n');
		count++;
	}
	myfile.close(); //count has the number of lines
	no_care = count - 20; //no_care has the first lines we dont want to use
	ifstream afile("audit.txt");
	getline(afile, kati, '\n'); //because we have error with 1st line blank
	if (no_care <= 0){
		for (int i = 0; i < count; i++){
			string data;
			getline(afile, data, '\n');
			cout << data << endl;
		}
	}
	else{
		for (int i = 0; i < no_care; i++){
			string data;
			getline(afile, data, '\n');
			cout << data << endl;
		}
	}
}
void director::Visibility(){
	cout << "please give the id of the node you want to hide" << endl;
	string choise;
	cin >> choise;
	string data;
	string **mydata;
	ifstream file("hierarcy.txt");
	int count = 0;
	while (file.good()){
		string thrash;
		getline(file, thrash, '\n');
		count++;
	}//count has the size of file
	file.close();
	ifstream afile("hierarcy.txt");
	mydata = new string*[count];
	for (int i = 0; i < count; i++){
		mydata[i] = new string[2];
	}
	for (int i = 0; i < count; i++){
		getline(afile, data, ' ');
		mydata[i][0] = data;
		getline(afile, data, '\n');
		mydata[i][1] = data;
	}
	afile.close();
	for (int i = 0; i < count; i++){
		if (choise == mydata[i][0]){
			string data2;
			data2 = data.substr(0, 3);
			if (data2 == "[H]"){
				string data3=choise;
				data3.append("/Already hidden");
				trader::audit("Visibility",data3);
				cout << "node already hidden" << endl;
				return;
			}
			else{
				trader::audit("Visibility",choise);
				string data3 = "[H]";
				data3.append(mydata[i][1]);
				mydata[i][1] = data3;
			}
		}
	}//now i should place mydata[][] back to file
	ofstream bfile("hierarcy.txt");
	for (int i = 0; i < count; i++){
		bfile << mydata[i][0];
		bfile << " ";
		bfile << mydata[i][1];
		bfile << "\n";
	}
	bfile.close();
	
}
void director::Rename(){
	cout << "Please give the id of the node you want to rename or press Cancel/Abort to cancel" << endl;
	int count = 0;
	string thrash;
	ifstream afile("hierarcy.txt");
	while (afile.good()){
		getline(afile, thrash, '\n');
		count++;
	}//count has the size of file
	afile.close();
	ifstream file("hierarcy.txt");
	string **myarray;
	myarray = new string*[count];
	for (int i = 0; i < count; i++){
		myarray[i] = new string[2];
	}
	for (int i = 0; i < count; i++){
		string thrash;
		getline(file, thrash, ' ');
		myarray[i][0] = thrash;
		getline(file, thrash, '\n');
		myarray[i][1] = thrash;
	}//file in myarray now
	file.close();

	for (int i = 0; i < count; i++){
		string kati;
		if (myarray[i][0] != nodes_level){ //PERIMENW TO NODES LEVEL NA DOULEPSEI SWSTA
			kati = myarray[i][0].substr(0, nodes_level.size());
			if (kati == nodes_level){
				cout << myarray[i][0] << " " << myarray[i][1] << endl;
			}
		}
	}
	string data;
	cin >> data;
	if ((data == "Cancel") || (data == "Abort") || (data == "a") || (data == "c")){
		if(data=="a"){
			trader::audit("Rename","Abort");
		}
		else if(data=="c"){
			trader::audit("Rename","Cancel");
		}
		else{
			trader::audit("Rename",data);
		}
		return;
	}
	else{
		cout << "Please give the new name" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < count; i++){
			if (myarray[i][0] == data){
				string mine = myarray[1][0];
				mine=mine.substr(0, 3);
				if (mine == "[H]"){
					mine = mine.append(name);
					name = mine;
				}
				myarray[i][1] = name;
			}
		}
		string data2;
		data2=data;
		data2.append("/");
		data2.append(name);
		trader::audit("Rename",data2);
	}
	ofstream bfile("hierarcy.txt");
	for (int i = 0; i < count; i++){
		bfile << myarray[i][0];
		bfile << " ";
		bfile << myarray[i][1];
		bfile << "\n";
	}
	bfile.close();
}
void director::New(){
	cout << "Please give the id of the node you want to add or press Cancel/Abort to cancel" << endl;
	int count = 0;
	string thrash;
	ifstream afile("hierarcy.txt");
	while (afile.good()){
		getline(afile, thrash, '\n');
		count++;
	}//count has the size of file
	afile.close();
	ifstream file("hierarcy.txt");
	string **myarray;
	myarray = new string*[count];
	for (int i = 0; i < count; i++){
		myarray[i] = new string[2];
	}
	for (int i = 0; i < count; i++){
		string thrash;
		getline(file, thrash, ' ');
		myarray[i][0] = thrash;
		getline(file, thrash, '\n');
		myarray[i][1] = thrash;
	}//file in myarray now
	file.close();
	int keeper;
	for (int i = 0; i < count; i++){
		string kati;
		if (myarray[i][0] != nodes_level){ //PERIMENW TO NODES LEVEL NA DOULEPSEI SWSTA
			kati = myarray[i][0].substr(0, nodes_level.size());
			if (kati == nodes_level){
				cout << myarray[i][0] << " " << myarray[i][1] << endl;
				keeper = i;
			}
		}
		else{
			keeper = i;
		}
	}//at the end keeper has the position of the last node we are interested to
	string data;
	cin >> data;
	if ((data == "Cancel") || (data == "Abort") || (data == "a") || (data == "c")){
		if(data=="a"){
			trader::audit("New","Abort");
		}
		else if(data=="c"){
			trader::audit("New","Cancel");
		}
		else{
			trader::audit("New",data);
		}
		return;
	}
	else{
		cout << "Please give the new node's name" << endl;
		string name;
		cin >> name;
		string data25;
		data25=data;
		data25.append("/");
		data25.append(name);
		trader::audit("New",data25);
		string **newarray;
		newarray = new string*[count + 1];
		for (int i = 0; i < (count + 1); i++){
			newarray[i] = new string[2];
		}
		for (int i = 0; i <= keeper; i++){
			newarray[i][0] = myarray[i][0];
			newarray[i][1] = myarray[i][1];
		}
		newarray[keeper + 1][1] = name;
		newarray[keeper + 1][0] = data;
		for (int i = keeper + 2; i < count + 1; i++){
			newarray[i][0] = myarray[i - 1][0];
			newarray[i][1] = myarray[i - 1][1];
		}
		//now i should write in file
		ofstream cfile("hierarcy.txt");
		for (int i = 0; i < (count + 1); i++){
			cfile << newarray[i][0];
			cfile << " ";
			cfile << newarray[i][1];
			cfile << "\n";
		}
		cfile.close();
	}
}
void director::Delete(){
	cout << "Please give the id of the node you want to delete or press Cancel/Abort to cancel" << endl;
	int count = 0;
	string thrash;
	ifstream afile("hierarcy.txt");
	while (afile.good()){
		getline(afile, thrash, '\n');
		count++;
	}//count has the size of file
	afile.close();
	ifstream file("hierarcy.txt");
	string **myarray;
	myarray = new string*[count];
	for (int i = 0; i < count; i++){
		myarray[i] = new string[2];
	}
	for (int i = 0; i < count; i++){
		string thrash;
		getline(file, thrash, ' ');
		myarray[i][0] = thrash;
		getline(file, thrash, '\n');
		myarray[i][1] = thrash;
	}//file in myarray now
	file.close();
	//int keeper;
	for (int i = 0; i < count; i++){
		string kati;
		if (myarray[i][0] != nodes_level){ //PERIMENW TO NODES LEVEL NA DOULEPSEI SWSTA
			kati = myarray[i][0].substr(0, nodes_level.size());
			if (kati == nodes_level){
				cout << myarray[i][0] << " " << myarray[i][1] << endl;
			}
		}
	}
	string data;
	int keeper;
	cin >> data;
	if ((data == "Cancel") || (data == "Abort") || (data == "a") || (data == "c")){
		if(data=="a"){
			trader::audit("Delete","Abort");
		}
		else if(data=="c"){
			trader::audit("Delete","Cancel");
		}
		else{
			trader::audit("Delete",data);
		}
		return;
	}
	else{
		for (int i = 0; i < count; i++){
			if (myarray[i][0] == data){
				keeper = i;
			}
		}//keeper has the position of the node we want to delete, we just put the array back in except of the myarray[keeper][]
		ofstream newfile("hierarcy.txt");
		for (int i = 0; i < count; i++){
			if (i != keeper){
				newfile << myarray[i][0];
				newfile << " ";
				newfile << myarray[i][1];
				newfile << "\n";
			}
		}
		newfile.close();
		string data18;
		data18.append(data);
		data18.append("/");
		data18.append(myarray[keeper][1]);
		trader::audit("Delete",data18);
	}
}
void director::Copy(){
	cout << "Please give the id of the node you want to copy or press Cancel/Abort to cancel" << endl;
	int count = 0;
	string thrash;
	ifstream afile("hierarcy.txt");
	while (afile.good()){
		getline(afile, thrash, '\n');
		count++;
	}//count has the size of file
	afile.close();
	ifstream file("hierarcy.txt");
	string **myarray;
	myarray = new string*[count];
	for (int i = 0; i < count; i++){
		myarray[i] = new string[2];
	}
	for (int i = 0; i < count; i++){
		string thrash;
		getline(file, thrash, ' ');
		myarray[i][0] = thrash;
		getline(file, thrash, '\n');
		myarray[i][1] = thrash;
	}//file in myarray now
	file.close();
	//int keeper;
	for (int i = 0; i < count; i++){
		string kati;
		if (myarray[i][0] != nodes_level){ //PERIMENW TO NODES LEVEL NA DOULEPSEI SWSTA
			kati = myarray[i][0].substr(0, nodes_level.size());
			if (kati == nodes_level){
				cout << myarray[i][0] << " " << myarray[i][1] << endl;
			}
		}
	}
	string data;
//	int keeper;
	cin >> data;
	if ((data == "Cancel") || (data == "Abort") || (data == "a") || (data == "c")){
		if(data=="a"){
			trader::audit("Copy","Abort");
		}
		else if(data=="c"){
			trader::audit("Copy","Cancel");
		}
		else{
			trader::audit("Copy",data);
		}
		return;
	}
	else{
//		string **newarray;
		int counter = 0;
		string **pinakas;
		int position;//estw counter to plithos ok kombwn pou na ginoun copy
		for (int i = 0; i < count; i++){
			if (myarray[i][0] == data){
				counter++;
				position = i;
			}
			else{
				string kati=myarray[i][0];
				if (kati.size() >= data.size()){
					kati = kati.substr(0, data.size());
					if (kati == data){//this means we have subnode
						counter++;
						position = i;
					}
				}
			}
		}
		pinakas = new string*[counter+1];
		for (int i = 0; i < counter+1; i++){
			pinakas[i] = new string[2];
		}
		int w = 0;
		for (int i=0; i < count; i++){
			if (myarray[i][0] == data){
				pinakas[w][0] = data;
				pinakas[w][1] = myarray[i][1];
				w++;
			}
			else{
				string kati = myarray[i][0];
				if (kati.size() >= data.size()){
					kati = kati.substr(0, data.size());
					if (kati == data){//this means we have subnode
						pinakas[w][0] = myarray[i][0];
						pinakas[w][1] = myarray[i][1];
						w++;
					}
				}
			}
		}//we placed the nodes to copy in the pinakas[][]
		string data80;
		data80.append(pinakas[0][0]);
		data80.append("/");
		data80.append(pinakas[0][1]);
		audit("Copy",data80);
		ofstream newfile("hierarcy.txt");
		for (int i = 0; i <= position; i++){
			newfile << myarray[i][0];
			newfile << " ";
			newfile << myarray[i][1];
			newfile << "\n";
		}
		for (int i = 0; i < counter; i++){
			newfile << pinakas[i][0];
			newfile << " ";
			string thrash = pinakas[i][1];
			thrash.append("-Copied");
			newfile <<thrash ;
			newfile << "\n";
		}
		for (int i = position+1; i < count; i++){
			newfile << myarray[i][0];
			newfile << " ";
			newfile << myarray[i][1];
			newfile << "\n";
		}
		newfile.close();
	}

}
bool director::empty(ifstream &myfile){
	return myfile.peek() == std::ifstream::traits_type::eof();
}
void director::Users(){
	cout << "Choose which node you want to visit" << endl;
	cout << "V (View)" << endl;
	cout << "S (Search)" << endl;
	cout << "L (Lock)" << endl;
	string myid;
	cin >> myid;
	if (myid == "V"){
		trader::audit("View","");
		View();
	}
	else if (myid == "S"){
		Search();
	}
	else if (myid == "L"){
		//audit("Bets", "");
		Lock();
	}
}
void director::View(){
	ifstream file("users.txt");
	string data;
	while (file.good()){
		for (int i = 0; i < 8; i++){
			getline(file, data, '|');
			cout << data << "|";
		}
		getline(file, data, '\n');
		cout << endl;
	}
	file.close();
}
void director::Search(){
	ifstream file("users.txt");
	string data,input;
	string pinakas[8];
	cout << "please give what you want to search" << endl;
	cin >> input;
	while (file.good()){
		for (int i = 0; i < 8; i++){
			getline(file, data, '|');
			pinakas[i] = data;
		}
		getline(file, data, '\n');
		size_t found = pinakas[1].find(input);
		if ( found!=-1){
			for (int i = 0; i < 8; i++){
				cout << pinakas[i] << "|";
			}
			cout << endl;
		}
	}
	trader::audit("Search",input);
}
void director::Lock(){
	ifstream afile("users.txt");
	string **pinakas;
	string thrash;
	int count = 0;
	while (afile.good()){
		getline(afile, thrash, '\n');
		count++;
	}
	afile.close();
	ifstream file("users.txt");
	pinakas = new string*[count];
	for (int i = 0; i < count; i++){
		pinakas[i]= new string[8];
	}
	for (int i = 0; i < count; i++){
		for (int j = 0; j < 8; j++){
			string data;
			getline(file, data, '|');
			pinakas[i][j] = data;
		}
		getline(file, thrash, '\n');
	}
	file.close();
	cout << "give the user you want to lock or unlock" << endl;
	string user;
	string reason;
	cin >> user;
	for (int i = 0; i < count; i++){
		if (pinakas[i][1] == user){
			if (pinakas[i][5]==" "){//lock proccess
				string lock="L";
				cout << "please give reason for this lock" << endl;
				cin.ignore();
				getline(cin, reason);
				lock.append(", ");
				lock.append(reason);
				pinakas[i][5] = lock;
				trader::audit("Lock",pinakas[i][1]);
			}
			else{
				string comment = pinakas[i][5].substr(0, 1);
				if (comment == "A"){
					string lock = "L";
					cout << "please give reason for this lock" << endl;
					cin.ignore();
					getline(cin, reason);
					lock.append("L, ");
					lock.append(reason);
					pinakas[i][5] = lock;
					trader::audit("Lock",pinakas[i][1]);
				}
				else{//unlock process
					trader::audit("Unlock",pinakas[i][1]);
					cout << "please give reason for this unlock or press space to clear" << endl;
					cin.ignore();
					getline(cin, reason);
					if (reason == " "){
						pinakas[i][5] = reason;
					}
					else{
						string unlock = "A";
						unlock.append(", ");
						unlock.append(reason);
						pinakas[i][5] = reason;
					}
				}
			}
			
		}
	}
	ofstream bfile("users.txt");
	for (int i = 0; i < count; i++){
		for (int j = 0; j < 8; j++){
			bfile << pinakas[i][j];
			bfile << "|";
		}
		if (i != 7){
			bfile << "\n";
		}
	}
	bfile.close();

}
void director::Bets(){
	trader::Bets();
}
void director::Freebets(){
	trader::Freebets();
}
void director::Settle(){
	trader::Settle();
}
void director::Void(){
	trader::Void();
}
