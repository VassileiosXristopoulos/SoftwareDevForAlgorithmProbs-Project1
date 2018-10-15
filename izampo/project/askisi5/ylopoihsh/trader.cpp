#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;
#include "trader.h"
trader::trader(int myid, string u, string f, string p,string s = "-", double b = 0, string fr = "0")
	:username(u), fullname(f), password(p), type(2), status(s), id(myid){
	user::foo("non");
}
trader::~trader(){}

string trader::Home(){
	string hi = user::Home();
	//string letter = navigate(hi);
	if (hi == "H"){
		audit("Home","");
		Home();
		return "H";
	}
	else if (hi == "T"){
		audit("Toggle", "");
		return "T";
	}
	else if (hi == "X"){
		audit("Exit","");
		return "X";
	}
	else{
		return hi;
	}

}
bool trader::empty(ifstream &myfile){
	return myfile.peek() == std::ifstream::traits_type::eof();
}
void trader::print_choises(string myid,string l){
	user::print_choises(myid,l);
	cout << "B(Bets)" << endl;
	cout << "F(Freebets)" << endl;
	if(level==5){
		cout << "S(Settling)" << endl;
		cout << "V(Voiding)" << endl;
	}
}
string trader::navigate(string myid,string l){
	if (l == "none"){
		print_choises(myid,l);
	}
	string num = user::navigate(myid, "subclass!",l);
	if (num == "H"){
		audit("Home","");
		return "H";
		//num = Home();
	}
	else if (num == "T"){
		audit("Toggle","");
		return "T";
	}
	else if (num == "B"){
		audit("Bets","");
		Bets();
		string letter = navigate(myid);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "F"){
		Freebets();
		string letter = navigate(myid);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "S"){
		Settle();
		string letter = navigate(myid);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}
	}
	else if (num == "V"){
		Void();
		string letter = navigate(myid);
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
		audit("Exit","");
		return "X";
	}
	else{
		// user::navigate returns id in num in this case
		/*string letter = navigate(num);
		if (letter == "H"){
			return "H";
		}
		else if (letter == "X"){
			return "X";
		}*/
		return num;
	}
}

void trader::Freebets(){
	cout << "Insert player's username!" << endl;
	string p_id;
	cin >> p_id;
	cout << "Now insert the amount of the freebet" << endl;
	double free, old_free;
	cin >> free;
	ifstream file("users.txt");
	int complete = 0;
	string first, thrash, third, money,u_name;
	while (file.good() && complete == 0){
		getline(file, thrash, '|');
		getline(file, u_name, '|');
		if (u_name == p_id){
			first.append(thrash);
			first.append("|");
			first.append(u_name);
			first.append("|");
			for (int i = 0; i<5; i++){
				string kati_allo;
				getline(file, kati_allo, '|');
				first.append(kati_allo);
				first.append("|");
			}
			getline(file, money, '|');
			if (money == " "){
				old_free = 0;
			}
			else{
				old_free =1;
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
	string s;
	if (old_free == 0){
		stringstream s1;
		s1 << free;
		s = s1.str();
	}
	
	else{
		stringstream s1;
		string s2;
		s = money;
		s.append(",");
		s1 << free;
		s2 = s1.str();
		s.append(s2);
	}
	first.append(s);
	first.append("|");
	third=third.substr(0,third.size()-1);
	first.append(third);
	ofstream myfile("users.txt");
	myfile << first;
	myfile.close();
	string data;
	data=p_id;
	data.append("/");
	stringstream free1;
	free1 << free;
	string s3 = free1.str();
	data.append(s3);
	audit("Freebets",data);
}

void trader::Bets(){
	ifstream myfile("bets.txt");
	int count = 0,no_care;
	while (myfile.good()){
		string thrash;
		getline(myfile, thrash, '\n');
		count++;
	}
	myfile.close(); //count has the number of lines
	no_care = count - 20; //no_care has the first lines we dont want to use
	ifstream file("bets.txt");
	if (no_care <= 0){
		while (file.good()){
			string data,result,thrash;
			getline(file, data, '|');
			getline(file, data, '|'); //data has the user id
			getline(file, result, '|');
			getline(file, result, '|');
			getline(file, result, '|'); //result has the result of the bet
			cout << "user id: " << data << " result " << result << endl;
			getline(file, thrash, '\n');
		}
	}
	else{
		for ( int i = 0; i < no_care; i++){
			string thrash;
			getline(file, thrash, '\n'); //reach the last 20 lines
		}
		while (file.good()){
			string data, result, thrash;
			getline(file, data, '|');
			getline(file, data, '|'); //data has the user id
			getline(file, result, '|');
			getline(file, result, '|');
			getline(file, result, '|'); //result has the result of the bet
			cout << "user id: " << data << " result " << result << endl;
			getline(file, thrash, '\n');
		}
	}
	file.close();

}

void trader::audit(string action_name,string data){
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
	if(data!=""){
		thrash.append(data);
		thrash.append("|");
	}
	thrash=thrash.substr(0,thrash.size()-1);
	file << thrash;
	file.close();
}

void trader::Settle(){
	cout << "Please give the result you want to settle" << endl;
	string choise;
	cin >> choise;
	string my_nodeid;
	string **bet;
	my_nodeid.append(fourth_level);
	my_nodeid.append(".");
	my_nodeid.append(choise);//my_nodeid has the id im looking for
	audit("Settling", my_nodeid);
	ifstream file("bets.txt");
	int count = 0;
	while (file.good()){
		string thrash;
		getline(file, thrash, '\n');
		count++;
	}//count has the number of lines in bets.txt
	file.close();
	//count--;
	bet = new string*[count];
	for (unsigned int i = 0; i < count; i++){
		bet[i] = new string[5];
	}
	ifstream myfile("bets.txt");
	for (unsigned int i = 0; i < count; i++){
		for (unsigned int j = 0; j < 5; j++){
			string thrash;
			getline(myfile, thrash, '|');
			bet[i][j] = thrash;
		}
		string kati;
		getline(myfile, kati, '\n');
	}//now bet[][] has all the data i need
	int keeper;
	myfile.close();
	for (unsigned int i = 0; i < count; i++){
		if (bet[i][2] == my_nodeid){
			bet[i][4] = "W";
			keeper = i;
		}
	}//now i've changed all the results, bet[][] goes back to file
	for (unsigned int i = 0; i < count; i++){
		string data;
		if (i != keeper){
			data = bet[i][2];
			data = data.substr(0, 7);
			if (data == fourth_level){
				bet[i][4] = "L";
			}
		}
	}
	ofstream afile("bets.txt");
	for (unsigned int i = 0; i < count; i++){
		for (unsigned int j = 0; j < 5; j++){
			afile << bet[i][j];
			afile << "|";
		}
		if (i != count - 1){
			afile << "\n";
		}
	}
	afile.close();
	//gainings' receipt
	ifstream bfile("bets.txt");
	int winner_count = 0;
	for (int i = 0; i<count; i++){
		if (bet[i][4] == "W"){
			winner_count++;
		}
	}
	string **winners;
	winners = new string*[winner_count];
	for (int i = 0; i < winner_count; i++){
		winners[i] = new string[4];
	}
	int j = 0;
	for (int i = 0; i<count; i++){
		if (bet[i][4] == "W"){
			winners[j][0] = bet[i][1];//->winner's id
			winners[j][1] = bet[i][2];//->winning bet(game)
			winners[j][2] = bet[i][3];//->winner's stake
			j++;
		}
	}
	bfile.close();
	for (j = 0; j<winner_count; j++){
		ifstream hfile("hierarcy.txt");
		int complete = 0;
		while (hfile.good() && (complete == 0)){
			string stuff, thrash;
			getline(hfile, stuff, ' ');
			if (stuff == winners[j][1]){
				string money, mult, over;
				getline(hfile, money, '#');
				getline(hfile, mult, '/');
				getline(hfile, over, '\n');
				int multer = atoi(mult.c_str());
				int overer = atoi(over.c_str());
				double temp = ((double)(multer + overer) / (double)(overer));
				double stake = atof(winners[j][2].c_str());
				double final = temp*stake - stake;
				double y = 100 * final;
 	 			int rounded = (int)(y + 0.5);
   				int x=rounded/100;
   				int z=rounded%100;
   				stringstream x1;
   				x1<<x;
   				string x2=x1.str();
   				stringstream z1;
   				z1 << z;
   				string z2=z1.str();
   				string s=x2;
   				x2.append(".");
   				x2.append(z2);
				winners[j][3] = x2;
				complete = 1;
			}
			else{
				getline(hfile, thrash, '\n');
			}
		}
		hfile.close();
	}
	ifstream binfile("users.txt");
	int my_counter = 0;
	while (binfile.good()){
		string thrash;
		getline(binfile, thrash, '\n');
		my_counter++;
	}
	binfile.close();

	ifstream infile("users.txt");
	string** cr_user;
	cr_user = new string*[my_counter];
	for (int i = 0; i<my_counter; i++){
		cr_user[i] = new string[8];
	}
	while (infile.good()){
		for (int i = 0; i<my_counter; i++){
			for (int j = 0; j<8; j++){
				string stuff;
				getline(infile, stuff, '|');
				cr_user[i][j] = stuff;
			}
			string thrash;
			getline(infile, thrash, '\n');
		}
	}
	infile.close();
	double x, y, f;
	for (int i = 0; i<winner_count; i++){
		for (int j = 0; j<my_counter; j++){
			if (winners[i][0] == cr_user[j][0]){
				if (cr_user[j][6] != ""){
					x = atof(cr_user[j][6].c_str());
				}
				else{
					x = 0;
				}
				y = atof(winners[i][3].c_str());
				f = x + y;
				stringstream s;
				s << f;
				string s1 = s.str();
				cr_user[j][6] = s1;
			}
		}
	}
	ofstream outfile("users.txt");
	for (int i = 0; i < my_counter; i++){
		for (int j = 0; j<7; j++){
			outfile << cr_user[i][j];
			outfile << "|";
		}
		outfile << cr_user[i][7];
		if (i != my_counter - 1){
			outfile << "|\n";
		}
		else{
			outfile << "|";
		}
	}
	outfile.close();
}
void trader::Void(){
	cout << "Please give the node you want to Void" << endl;
	string choise, my_nodeid;
	cin >> choise;
	my_nodeid.append(fourth_level);
	my_nodeid.append(".");
	my_nodeid.append(choise);//my_nodeid has the id im looking for

	ifstream file("hierarcy.txt");
	int count = 0;
	while (file.good()){
		string thrash;
		getline(file, thrash, '\n');
		count++;
	}//count has the number of lines in hierarcy.txt
	file.close();
	string **nodes;
	nodes = new string*[count];
	for (int i = 0; i < count; i++){
		nodes[i] = new string[2];
	}
	ifstream afile("hierarcy.txt");
	for (int i = 0; i < count; i++){
		string thrash;
		getline(afile, thrash, ' ');
		nodes[i][0] = thrash;
		getline(afile, thrash, '\n');
		nodes[i][1] = thrash;
	}//nodes has all the file
	afile.close();
	for (int i = 0; i < count; i++){
		if (nodes[i][0] == my_nodeid){
			string data;
			data.append("[V]");
			data.append(nodes[i][1]);
			nodes[i][1] = data;
		}
	}
	ofstream myfile("hierarcy.txt");
	for (int i = 0; i < count; i++){
		myfile << nodes[i][0];
		myfile << " ";
		myfile << nodes[i][1];
		myfile << "\n";
	}
	cout << "This node is now Voided!" << endl;
	myfile.close();
	//////////////////////////
	ifstream bfile("bets.txt");
	int pcount = 0;
	while (bfile.good()){
		string thrash, stuff;
		for (int i = 0; i<2; i++){
			getline(bfile, thrash, '|');
		}
		getline(bfile, stuff, '|');
		if (stuff == my_nodeid){
			pcount++;
		}
		getline(bfile, thrash, '\n');
	}
	bfile.close();
	ifstream gfile("bets.txt");
	string** players;
	players = new string*[pcount];
	for (int i = 0; i<pcount; i++){
		players[i] = new string[2];
	}
	int i = 0;
	while (gfile.good()){
		string* stuff;
		stuff = new string[5];
		for (int j = 0; j<4; j++){
			getline(gfile, stuff[j], '|');
		}
		string thrash;
		getline(gfile, thrash, '\n');
		if (stuff[2] == my_nodeid){
			players[i][0] = stuff[1];//players' id
			players[i][1] = stuff[3];//players' stack
			i++;
		}
		delete[] stuff;
	}
	gfile.close();

	ifstream binfile("users.txt");
	int my_counter = 0;
	while (binfile.good()){
		string thrash;
		getline(binfile, thrash, '\n');
		my_counter++;
	}
	binfile.close();

	ifstream infile("users.txt");
	string** cr_user;
	cr_user = new string*[my_counter];
	for (int i = 0; i<my_counter; i++){
		cr_user[i] = new string[8];
	}
	while (infile.good()){
		for (int i = 0; i<my_counter; i++){
			for (int j = 0; j<8; j++){
				string stuff;
				getline(infile, stuff, '|');
				cr_user[i][j] = stuff;
			}
			string thrash;
			getline(infile, thrash, '\n');
		}
	}

	infile.close();
	double f, x, y;
	for (int j = 0; j<pcount; j++){
		for (int i = 0; i<my_counter; i++){
			if (cr_user[i][0] == players[j][0]){
				if (cr_user[i][6] != ""){
					x = atof(cr_user[i][6].c_str());
				}
				else{
					x = 0;
				}
				y = atof(players[j][1].c_str());
				f = x + y;
				stringstream s;
				s << f;
				string s1 = s.str();

				cr_user[i][6] = s1;
			}
		}
	}
	ofstream outfile("users.txt");
	for (int i = 0; i < my_counter; i++){
		for (int j = 0; j<7; j++){
			outfile << cr_user[i][j];
			outfile << "|";
		}
		outfile << cr_user[i][7];
		if (i != my_counter - 1){
			outfile << "|\n";
		}
		else{
			outfile << "|";
		}
	}
	outfile.close();

	audit("Voiding", my_nodeid);
}
