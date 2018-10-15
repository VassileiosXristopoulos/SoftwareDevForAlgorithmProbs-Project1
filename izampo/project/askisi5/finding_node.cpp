#include <iostream>
#include <fstream>
using namespace std;
#include <string>
	
	int main(void){
	string data = "1.1.1 Hello World";
	int keeper;
	for (int i = 0; i < data.length(); i++){
		if (data[i] == ' '){
			keeper = i;
			break;
		}
	}
	if (keeper==3)//protos komvos
		if (keeper==4)//2os komvos
			if (keeper==6)//3os komvos
				if (keeper==8)//4os komvos
					if (keeper==10)//5os komvos
///// analoga poion komvo theloyme afou ton exoume vrei diaxorizoume thn plhroforia tou
	data=data.substr(keeper + 1);
	cout << data << endl;
	cin.clear();
	cin.ignore();
	cin.get();
}
