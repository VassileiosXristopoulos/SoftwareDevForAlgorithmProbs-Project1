#include <iostream>
#include <ctime>
#include<cstdlib>
#include "unions.h"


int main(void){
	atom ***p;
	std::srand(time(0));
	 int size,counter;
	 int c_counter = 0;
	 int h_counter = 0;
	int  N,N1,v, loops,found;

	std::cout << "give number of loops " << std::endl;
	std::cin >> loops;
	for (int k = 0; k<loops; k++){
		N = rand() % 10;

		atom ***p = new atom**[N];
		counter = 0;
		N1 = N;
		while (N>0){
			found = 1;
			size = rand() % (N + 1);
			v = rand()%3+1; 				//(v=1)=alkanio (v=2)=alkenio (v=3)=alkinio
			unions u(p, size, counter, N1);
			if (v == 1){
				h_counter += 2 * size + 2;
				c_counter += size;
				u.alcanium(counter, size, p);
//				u.print(c_counter, h_counter, size,v);
				c_counter = 0;
				h_counter = 0;
			}
			else if (v == 2){
				if (size >= 2){
					c_counter += size;
					h_counter += 2 * size;
					u.alcenium(counter, size, p);
					//u.print(c_counter, h_counter, size,v);
					c_counter = 0;
					h_counter = 0;
				}
				else{
					found = 0;
				}
			}
			else {
				if (size >= 2){
					c_counter += size;
					h_counter += 2 * size - 2;
					u.alcinium(counter, size, p);
				//	u.print(c_counter, h_counter, size,v);
					c_counter = 0;
					h_counter = 0;
				}
				else{
					found = 0;
				}
			}
			if (found == 1){
				counter += size;
				N -= size;
			}
		}
		delete[] p;
	}
	
	std::cout << "end succeded" << std::endl;
}

