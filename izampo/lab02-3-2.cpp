#include<iostream>

using namespace std;


int main(void){

	int minCharge=3;
	float rate=0.15;
	int start=200;
	cout<<"to arxiko poso einai:"<<start<<endl;
	cout<<"elaxisti xrewsi einai:"<<minCharge<<endl;
	cout<<"to epitokio einai:"<<rate<<endl;
	float final=start+(start*rate*12)-3;
	cout<<"to teliko poso einai:"<<final<<endl;
}
