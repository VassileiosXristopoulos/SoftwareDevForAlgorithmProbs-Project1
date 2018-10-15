#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;
int idd=100001;
 int C=100;
 typedef struct dema{
	int id;
	int idKatastimatos;
	int xwros;
};
vector <int> capacity_vector;
int log_funct(){
	int rand_var=rand();
	int log_var=log(rand_var);
	return log_var;
}


dema function(int katastima){
  	vector<dema>my_vector;
  	my_vector[katastima].idKatastimatos=katastima;
  	my_vector[katastima].id=idd++;
	my_vector[katastima].xwros=log_funct();
  	  	return my_vector[katastima];
  }
  
 vector<int> capacity_funct(vector<dema>myVector2){
  	vector<int>newvector;
  for(int i=0;i<10;i++){
  	if(myVector2[i].xwros<C){
  		newvector[i]+=myVector2[i].xwros;
  		C=C-myVector2[i].xwros;
	  }
  }
 return newvector;
  }
int main(void){
	vector<dema>dema_vector;
	vector<int>capacityVector;
	for(int i=0;i<10;i++){
	dema_vector[i]=	function(i);
	}
capacityVector[N]=	function(dema_vector[]);
}
