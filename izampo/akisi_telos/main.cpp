#include <iostream>
#include <ctime>
#include<cstdlib>
#include "atom.h"
int main(void){
	std::srand(time(0));
	unsigned int size;
	int K,N,v,loops;
	atom ***pt;
	std::cout<<"give number of loops "<<std::endl;
	std::cin>> loops;
	for(int k=0;k<loops;k++){
//	std::srand(time(0));
//	Í=std::rand()%10;
	N=5;
	
	atom ***pt=new atom**[N];
//	for(int i=0;i<N;i++){
//		pt[i]=NULL;
//	}
		for(int i=0;i<N;i++){
		atom a(N);
		pt[i]=a.p;
		}
		while(K>0){
		do{
			v=rand(); 		//(v=1)=alkanio (v=2)=alkenio (v=3)=alkinio
		}while( (v==1) || (v==2) || (v==3) );
		if( (v==1)&& (K>=1) ){
			do{
			size=rand();
			}while( (size>K)&& (size==0) );	//exw K anthrakes kai kanoun aplo desmo metaksi tous kai ola ta alla udrogona
			K-=size;
			for(int i=0;i<(size-1);i++){
				pt[i][0]=*pt[i+1];
				pt[i+1][0]=*pt[i];
			}
			for(int i=0;i<size;i++){
				for(int j=1;j<4;j++){
					pt[i][j]=new atom(1);
				}
			}
		}
		else if( (v==2)&& (K>=2) ){
			do{
			size=rand();
			}while(size>K);
			pt[0][0]=*pt[1];
			pt[1][0]=*pt[0];
			pt[0][1]=*pt[1];
			pt[1][1]=*pt[0];
			for(int i=0;i<2;i++){
				pt[i][3]=new atom(1);
				pt[i][4]=new atom(1);
			}
			for(int i=2;i<size;i++){
				pt[i][0]=*pt[i-1];
				for(int j=1;j<4;j++){
					pt[i][j]=new atom(1);
				}
			}
			
		}
		else if( (v==3)&&(K>=2) ){
			do{
			size=rand();
			}while(size>K);	
			pt[0][0]=*pt[1];
			pt[0][1]=*pt[1];
			pt[0][2]=*pt[1];
			pt[1][0]=*pt[0];
			pt[1][1]=*pt[0];
			pt[1][2]=*pt[0];
			pt[0][3]=new atom(1);
			pt[1][3]=new atom(1);
		}
		
	}
  }
  delete [] pt;
}

