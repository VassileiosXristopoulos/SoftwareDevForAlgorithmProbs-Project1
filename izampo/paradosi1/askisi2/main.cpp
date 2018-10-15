#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include "atom.h"
int main(void){
	srand((unsigned int)time(NULL));
	int copy,N,found,v,size, loops,start;
	int hydrogens;
	std::cout << "give number of loops " << std::endl;
	std::cin >> loops;
	start = 0;
	for (int k = 0; k < loops; k++){
		N = rand()%20 ;
		atom *table[N];
		for (int i = 0; i < N; i++){
			table[i] = new atom(4,i);
		}
		hydrogens = 1;
		start = 0;
		while (start<N){
			found = 0;
			v = rand() % 3 + 1;
			size = rand() % ((N-start) + 1);
			if (v == 1){
				if (size == 1){
					found = 1;
					std::cout << "comp([";
					for (int i = start; i < (start + size); i++){
						table[i]->alcanium(table, i, hydrogens, size);
					}
				}
				else if(size>1){
				    found=1;
					std::cout << "comp([";
					for (int i = start; i < (start + size-1); i++){
						table[i]->alcanium(table, i, hydrogens, size);
					}
				}
				if (size > 0){
				found=1;
					for (int j = start; j < (start + size); j++){
						table[j]->print(table, start, j, size);
					}

					std::cout << "])" << std::endl;
				}
				hydrogens += 2 * size + 2;
			}
			else if ((v == 2) && (size >= 2)&&((N-start)>=2)){
				found = 1;
				std::cout << "comp([";
				for (int i = start; i < (start + size-1 ); i++){
					table[i]->alcenium(table, i, start,hydrogens);
				}
				for (int j = start; j < (start + size ); j++){
					table[j]->print(table, start,j, size);
					//table[j+1]->print(table, start, j+1, size);
				}
				std::cout << "])" << std::endl;
				hydrogens += 2*size;
			}
			else if ((v == 3) && (size >= 2) && ((N-start) >= 2)){
				found = 1;
				std::cout << "comp([";
				for (int i = start; i <(start + size-1 ); i++){
					table[i]->alcinium(table, i, start,hydrogens);
				}
				for (int j = start; j < (start + size ); j++){
					table[j]->print(table, start,j, size);
				//	table[j+1]->print(table, start, j+1, size);
				}
				std::cout << "])" << std::endl;
				hydrogens += size * 2-2;
			}
			if (found == 1){
				start += size; 
			}
		}
		for (int i = 0; i < N; i++){
			delete table[i];
		}
		std::cout << std::endl << "------------------" << std::endl;
	}
}
