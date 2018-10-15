#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <iostream>
#include <string>
#include <fstream>
#include "trader.h"
using namespace std;
class director :public trader{

public:
	director(int, string, string, string, string, double, string);
	~director();
	void print_choises(string);
	string navigate(string);
	int Home();
	void Logs();
	void Visibility();
	void Rename();
	void New();
	void Delete();
	void Copy();
	bool empty(ifstream&);
	void Users();
	void View();
	void Search();
	void Lock();
	//bool empty(ifstream &);
	void Bets();
	void Freebets();
	void Void();
	void Settle();
	//void audit(string, string);
};
#endif