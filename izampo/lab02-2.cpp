#include <iostream>
#include <string>
#include<map>
int main(void){
	using namespace std;
	map<int ,string>my_map;

	my_map[1]="Hello World";
	cout<<my_map[1]<<endl;
	cout<<my_map[1].size()<<endl;
	cout<<my_map[1].length()<<endl;
	cout<<my_map[1].capacity()<<endl;
	if(my_map[1].empty()){
		cout<<"the map is empty"<<endl;
	}
	else{
		cout<<"the map is not epmty"<<endl;
	}
}
		/*if(s2.empty()){
		cout<<"the string s2 empty"<<endl;
	}
	else{
		cout<<"the string s2 is not epmty"<<endl;
	}
	
	cout<<s1<<endl;
	for(int i=0;i<s1.size();i++){
		cout<<s1[i];
	}
	cout<<endl;
	for(int i=0;i<s1.size();i++){
		cout<<s1.at(i);
	}
	cout<<endl;
	s1.append("!!")	;
	cout<<s1<<endl;
	s1.insert(s1.size()-2,"from DiT");
	cout<<s1<<endl;
	
	
	
}*/
