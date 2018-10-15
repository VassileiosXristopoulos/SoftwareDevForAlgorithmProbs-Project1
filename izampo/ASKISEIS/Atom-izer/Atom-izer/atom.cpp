#include "atom.h"
#include <iostream>
atom::atom(int num,int capacity){
	number = num;
	if (num == 1){
		id[1] = 'h';
		found=1;
		counter = 1 + capacity;
	}
	else if(num == 4){
	 found=0;
		id[1] = 'c';
		counter = 1 + capacity;
	}
	if (number == 4){
		atom_array = new atom*[num];
		for (int i = 0; i < num; i++){
			atom_array[i] = 0;
		}
	}
	else{
		hydrogens = new atom*[number];
		hydrogens[0] = 0;
	}
}
atom::~atom(){
	delete[] atom_array;
}
 void atom::alcanium(atom**arr, int position,int hydrogen,int size){
	static int count = 0;
	while (arr[position]->atom_array[count] != 0){
		count++;
	}
	if (size == 1){
		for (int i = 0; i < 4; i++){
			arr[position]->atom_array[i] = new atom(1, hydrogen);
			hydrogen++;
			arr[position]->atom_array[i]->hydrogens[0] = arr[position];
		}
	}
	else{
		arr[position]->atom_array[count] = arr[position + 1];
		arr[position + 1]->atom_array[0] = arr[position];
		for (int i = 0; i < 4; i++){
			if (arr[position]->atom_array[i] == 0){
				arr[position]->atom_array[i] = new atom(1, hydrogen);
				hydrogen++;
				arr[position]->atom_array[i]->hydrogens[0] = arr[position];
			}
		}
		for (int i = 0; i < 4; i++){
			if (arr[position + 1]->atom_array[i] == 0){
				arr[position + 1]->atom_array[i] = new atom(1, hydrogen);
				hydrogen++;
				arr[position + 1]->atom_array[i]->hydrogens[0] = arr[position + 1];
			}
		}
	}
}
void atom::alcenium(atom **arr, int position,int start1,int hydrogen){
	static int count = 0;

	while (arr[position]->atom_array[count] != 0){
		count++;
	}
	if (position == start1){ //diplos desmos
		arr[position]->atom_array[0] = arr[position + 1];
		arr[position]->atom_array[1] = arr[position + 1];
		arr[position + 1]->atom_array[0] = arr[position];
		arr[position + 1]->atom_array[1] = arr[position];
	}
	else{
		arr[position]->atom_array[count] = arr[position + 1];
		arr[position + 1]->atom_array[0] = arr[position];
	}
	for (int i = 0; i < 4; i++){
		if (arr[position]->atom_array[i] == 0){
			arr[position]->atom_array[i] = new atom(1,hydrogen);
			hydrogen++;
			arr[position]->atom_array[i]->hydrogens[0] = arr[position];
		}
	}
	for (int i = 0; i < 4; i++){
		if (arr[position+1]->atom_array[i] == 0){
			arr[position+1]->atom_array[i] = new atom(1, hydrogen);
			hydrogen++;
			arr[position+1]->atom_array[i]->hydrogens[0] = arr[position+1];
		}
	}
}

void atom::alcinium(atom**arr, int position, int start1,int hydrogen){
	static int count = 0;

	while (arr[position]->atom_array[count] != 0){
		count++;
	}
	if (position == start1){ 
		arr[position]->atom_array[0] = arr[position + 1];
		arr[position]->atom_array[1] = arr[position + 1];
		arr[position]->atom_array[2] = arr[position + 1];
		arr[position + 1]->atom_array[0] = arr[position];
		arr[position + 1]->atom_array[1] = arr[position];
		arr[position + 1]->atom_array[2] = arr[position];
	}
	else{
		arr[position]->atom_array[count] = arr[position + 1];
		arr[position + 1]->atom_array[0] = arr[position];
	}
	for (int i = 0; i < 4; i++){
		if (arr[position]->atom_array[i] == 0){
			arr[position]->atom_array[i] = new atom(1, hydrogen);
			hydrogen++;
			arr[position]->atom_array[i]->hydrogens[0] = arr[position];
		}
	}
	for (int i = 0; i < 4; i++){
		if (arr[position + 1]->atom_array[i] == 0){
			arr[position + 1]->atom_array[i] = new atom(1, hydrogen);
			hydrogen++;
			arr[position + 1]->atom_array[i]->hydrogens[0] = arr[position + 1];
		}
	}
}
void atom::print(atom**arr,int start,int w,int size){
		if ((w != size )&&(w!=start)){
			std::cout << ",";
		}
		int i = 0;
		std::cout << arr[w]->id[1] << arr[w]->counter << "(";
			if( (arr[w]->atom_array[0]->counter == arr[w]->atom_array[2]->counter) && (arr[w]->atom_array[0]->id[1]==arr[w]->atom_array[2]->id[1]) ){
				std::cout << "(triple)" << arr[w]->atom_array[0]->id[1] << arr[w]->atom_array[0]->counter << "," << arr[w]->atom_array[3]->id[1] << arr[w]->atom_array[3]->counter;
				std::cout << ")";
			}
			else if ( (arr[w]->atom_array[0]->counter == arr[w]->atom_array[1]->counter) && (arr[w]->atom_array[0]->id[1]==arr[w]->atom_array[1]->id[1]) ){
				std::cout << "(double)" << arr[w]->atom_array[0]->id[1] << arr[w]->atom_array[0]->counter << ",";
				std::cout << arr[w]->atom_array[2]->id[1] << arr[w]->atom_array[2]->counter <<", "<< arr[w]->atom_array[3]->id[1] << arr[w]->atom_array[3]->counter;
				std::cout << ")";
				delete [] hydrogens;

			}
			else{
				for (int i = 0; i < 4; i++){
					std::cout << arr[w]->atom_array[i]->id[1] << arr[w]->atom_array[i]->counter;
					if (i != 3){
						std::cout << ",";
					}
				}
			}
    for( int i=0;i<4;i++ ){
     if(arr[w]->atom_array[i]->id){
       delete []arr[w]->atom_array[i]->hydrogens;
       }
    }
		std::cout << ")";
}
