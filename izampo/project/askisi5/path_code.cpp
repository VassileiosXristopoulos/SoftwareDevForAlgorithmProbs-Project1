#include <iostream>
#include <fstream>
using namespace std;
#include <string>
void func2(string path){
	string s = path;
	s.append("/Leak");
	cout << s << endl;
}
void func1(string path){
	string s = path;
	s.append("/Parse");
	cout << s << endl;
	string entry;
	std::cin >> entry;
	if (entry == "L"){
		func2(s);
	}
}

int main(void){
	string path = "Home";
	string entry;
	std::cin >> entry;
	cout << path << endl;
	if (entry == "P"){
		func1(path);
	}
	/*cout << path << endl;
	cin.clear();
	cin.ignore();
	cin.get();*/
}


