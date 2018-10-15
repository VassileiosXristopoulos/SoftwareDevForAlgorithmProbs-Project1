#ifndef PUNTER_H
#define PUNTER_H
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
using namespace std;
class punter :public user{
	int id;
	string username;
	string fullname;
	string password;
	int type;
	string status;
	double balanace;
	string freebets;
public:
	punter(int, string, string, string, string, double, string);
	~punter();
	int Home();
	void Account();
	void Bets();
	string navigate(string,string s="none");
	void print_choises(string,string s="none");
	//void Account();
	void Rename();
	void Password();
	void Place();
	void Deposit();
	void audit(string, string);
	bool empty(ifstream&);
};
#endif
