#include <iostream>
using namespace std;
class playground{
	int capacity
	int children_in;
	seesaws see;
	war *ptr;
public:
	playground(int i,int war_cap,int see_cap,int j=0):capacity(i),children_in(j),see(see_cap){
		ptr=new war(war_cap);
		cout<<"i just created a playground"<<endl;
	}
	~playground(){
		cout<<"i just deleted a playground"<<endl;
	}
	void enter(int dinami,char * filo){
		if( (capacity-children_in) >0 ){
			children_in++;	
			if(ptr->enter(dinami)){
				see.enter(dinami,filo);
			}		
		}
		else{
			cout<<"playground full"<<endl;
		}
	}
};
class war{
	int capacity;
	int left_children;
	int right_children;
	list right_list;
	list left_list;
public:
	war(int i,int j=0,int k=0):capacity(i),left_children(j),right_children(k){
		cout<<"i just created a war"<<endl;
	}
	~war(){
		cout<<"i just deleted a war"<<endl;
	}
	void enter(int dinami){
		if(capacity-(left_children+right_children)>0){
			if( (left_children-right_children)>0){
					while(right_list.value>dinami){
						right_list=right_list.next;
					}
					right_list.push();
				
				right_children++;
			}
			else if(left_children==right_children){
				if(right_list==0){
					right_list.push_at_start();
				}
				else{
					while(right_list.value>dinami){
						right_list=right_list.next;
					}
					right_list.push();
				}
				right_children++;
			}
			else{
					while(right_list.value>dinami){
						right_list=right_list.next;
					}
					right_list.push();
				}
				left_children++;
			}
			return 0;
		}
		else{
			cout<<"war full"<<endl;
			return 1;
		}
	}
};
class seesaws{
	seesaws array*[5];
	public:
		seesaws(){
			for(int i=0;i<5;i++){
				array[i]=new seesaw();
			}
		}
		void enter(char *filo){
			for(int i=0;i<5;i++){
				if(array->enter(filo)){
					break;
				}
			}
		}
};
class seesaw{
	char* right_child;
	char* left_child;
public:
	seesaw(int i=0,int j=0):left_child(i),right_child(j){
		cout<<"i just created a seasaw"<<endl;
	}
	~seasaw(){}
	int enter(char * filo){
		if((right_child==0)&&(left_child==0)){
			right_child=filo;
			return 1;
		}
		else if( !((right_child==0)||(left_child==0)) ){
			return 0;
		}
		else if((right_child==0)&&(left_child!=0)){
			if(left_child=filo){
				right_child=left_child;
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
		if(right_child=filo){
				right_child=left_child;
				return 1;
			}
			else{
				return 0;
			}	
		}
	}
};

