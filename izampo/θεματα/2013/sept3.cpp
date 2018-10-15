#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
using namespace std;
class iceskater{
	string filo;
public:
	iceskater(string name) :filo(name){
		cout << "iceskater constucted" << endl;
	}
	~iceskater(){
		cout << "i am glinding out " << filo << endl;
	}
	string get_filo(){
		return filo;
	}
};
class couple{
	iceskater *left;
	iceskater *right;
public:
	couple():left(0),right(0){
	}
	enter(iceskater **array,int number){
		if(left==0){
			if(right==0){
				right=array[number];
			}
			else{
				if(right->get_filo()!=array[number]->get_filo()){
					left=array[number];
					return 1;
				}
				else{
					return 0;
				}
			}
		}
		else {
			if(right==0){
				if(left->get_filo()!=array[number]->get_filo()){
					right=array[number];
					return 1;
				}
				else{
					return 0;
				}
			}
			else{
				return 0;	
			}
		}
	}
};
class sschain{
	int capacity;
	iceskater **array;
public:
	sschain(int i):capacity(i){
		array=new iceskater*[capacity];
		for(int i=0;i<capacity;i++){
			array[i]=0;
		}
	}
	~sschain(){}
	int enter(iceskater **array,int number){
		for(int i=0;i<capacity;i++){
			if(array[i]==0){
				array[i]=array[number];
				return 1;
			}
		}
		return 0;
	}
	iceskater& get_skater(int i){
		return *array[i];
	}
};
class chain{
	iceskater **array;
	int number;
public:
	chain(int num){
		number=num;
		array=new iceskater*[num];
		for(int i=0;i<num;i++){
			array[i]=0;
		}
	}
	~chain(){
		for(int i=0;i<number;i++){
			delete (array[number]);
		}
	}
	void enter(iceskater &man,iceskater &woman,int capacity){
		for(int i=1;i<capacity;i++){
			if(array[i-1]==0){
			array[i-1]=&man;
			array[i]=&woman;
			}
		}
	}
};
class scene{
	int capacity;
	int num_couples;
	couple ** couples;
	sschain *menchain;
	sschain *womenchain;
	chain *my_chain;
public:
	scene(int i,int j):capacity(i){
		couples=new couple*[j];
		num_couples=j;
		int num=( capacity-(j*2) )/2;
		menchain=new sschain(num);
		womenchain=new sschain(num);
		my_chain=new chain( capacity-(j*2) );
		cout << "scene just constructed" << endl;
	}
	~scene(){
		cout << "scene just deleted" << endl;
	}
	int enter(iceskater **array,int number){
		if(capacity){
			int found=0;
			for(int i=0;i<num_couples;i++){
				if( (couples[i]->enter(array,number)) ){
					int found=1;
				}	
			}
			if(found){
				return found;
			}
			else{
				int found2=0;
				int total=0;
				if(array[number]->get_filo()=="M"){
						if( !(menchain->enter(array,number) )){
							total++;
						}
					}
					else{
						 if(!(womenchain->enter(array,number)) ){
						 	total++;
						 }
					}
					if(total==2){
						for(int i=0;i<(capacity-num_couples);i++){
							my_chain->enter(menchain[i].get_skater(i),womenchain[i].get_skater(i),capacity-(num_couples*2));
						}
					}
			}
		}
		else{
			cout<<"no room in the scene"<<endl;
			return 0;
		}
	}
	
};

int main(void){
	srand(time(NULL));
	scene my_scene(50,20);
	iceskater *array[50];
	for(int i=0;i<50;i++){
		int num=rand()%2;
		if(num){
		array[i]=new iceskater("M");
		}
		else{
		array[i]=new iceskater("F");
		}
	}
	int i=0;
	//cout<<"done"<<endl;
//	iceskater skater("F");
	while( (my_scene.enter(array,i)!=0) && (i<50) ){
		i++;
	//	iceskater skater("F");
	}
	for(int i=0;i<50;i++){
		//delete array[i];
	}
}
