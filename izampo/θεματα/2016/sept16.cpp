#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class paketo{
	address adr;
	int monades_dianomis;
public:
	paketo(int d,string r,int monades):adr(d,r),monades_dianomis(monades){
		
	}
	~paketo(){
		
	}
};
class address{
	int number;
	string road;
public:
	adress(int d,string r):number(d),road(r){
		
	}
	~adress(){
		
	}
};
class gramma:public paketo{
	
public:
	gramma(int d,string r,int monades):paketo(d,r,monades){
	}
	~gramma(){
		
	}
};
class sub_gramma:public gramma{
	string id;
public:
	sub_gramma(int d,string r,string my_id,int monades=2):gramma(d,r,monades),id(my_id){
		
	}
	~sub_gramma(){
	}
};
class dema:public paketo{
public:
	dema(int d,string r,int monades):paketo(d,r,monades){
		
	}
	~dema(){
	}
};
class kentro{
	list <paketo> my_list;
	list <sub_gramma> epeigon_gramma;
public:
	kentro(){}
	void arrive(paketo **array,int i){
		if(array[i]->monades_dianomis==2){
			if(array[i]->id=="epeigon"){
				epeigon_gramma.append(array[i]);
				return;
			}
			else{
						my_list.append(array[i]);
						return;
			}
		
		}
		my_list.append(array[i]);
	}
};
int main(void){
	kentro center;
	paketo **array;
	array=new dema*[10];
	for(){
	center.arrive(array,i);
	}
}
