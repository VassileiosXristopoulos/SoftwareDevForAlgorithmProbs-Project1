#ifndef TRADER_H
#define TRADER_H
#include <iostream>
#include <string>
#include "user.h"
using namespace std;
class trader :public user{
protected:
	int id;
	string username;
	string fullname;
	string password;
	int type;
	string status;
	double balanace;
	string freebets;
public:
	trader(int, string, string, string, string, double, string);
	~trader();
	void print_choises(string,string l="none");
	string Home();
	void Bets();
	void Freebets();
	void Void();
	void Settle();
	string navigate(string,string l="none");
	void audit(string, string);
	bool empty(ifstream&);
};
#endif