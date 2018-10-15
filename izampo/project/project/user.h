#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;
class user{
     string path;
protected:
	int level;
	string nodes_level;
	string fourth_level;
	int able;
public:
	user();
	~user();
	string Home();
	string navigate(string, string op = "none",string l="none");
	void foo(string);
	void print_nodes(string,string );
	void print_choises(string,string l="none");
	void Toggle(string);
	void audit(string);
	bool empty(ifstream&);
};
#endif
