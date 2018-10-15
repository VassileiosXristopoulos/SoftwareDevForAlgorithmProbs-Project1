#include "atom.h"
#include <iostream>
atom::atom(int num,int capacity){
	number = num;
	if (number == 1){
		id[1] = 'h';
		counter = 1 + capacity;
	}
	else if(number == 4){
		id[1] = 'c';
		counter = 1 + capacity;
	}
	if (number == 4){
		atom_array = new atom*[number];
		for (int i = 0; i < number; i++){
			atom_array[i] =0;
		}
	}
	else{
		hydrogens = new atom*[number];
	}
}
atom::~atom(){
	delete[] atom_array;
}
 void atom::alcanium(atom**arr, int position,int hydrogen,int size){
	 int count = 0;
	while ((arr[position]->atom_array[count] != 0)&&(count<3)){
		count++;
	}
	if (size == 1){
		for (int i = 0; i < 4; i++){
			arr[position]->atom_array[i] =new atom(1, hydrogen);//new 
			hydrogen++;
			arr[position]->atom_array[i]->hydrogens[0] = arr[position];
		}
	}
	else{
		arr[position]->atom_array[count] = arr[position + 1];
		arr[position + 1]->atom_array[0] = arr[position];
		for (int i = 0; i < 4; i++){
			if (arr[position]->atom_array[i] == 0){
				arr[position]->atom_array[i] =new  atom(1, hydrogen);//new
				hydrogen++;
				arr[position]->atom_array[i]->hydrogens[0] = arr[position];
			}
		}
		for (int i = 0; i < 4; i++){
			if (arr[position + 1]->atom_array[i] == 0){
				arr[position + 1]->atom_array[i] =new  atom(1, hydrogen);//new
				hydrogen++;
				arr[position + 1]->atom_array[i]->hydrogens[0] = arr[position + 1];
			}
		}
	}
}
void atom::alcenium(atom **arr, int position,int start1,int hydrogen){
	 int count = 0;
	while ((arr[position]->atom_array[count] != 0)&&(count<3)){
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
			arr[position]->atom_array[i] =new  atom(1,hydrogen);//new
			hydrogen++;
			arr[position]->atom_array[i]->hydrogens[0] = arr[position];
		}
	}
	for (int i = 0; i < 4; i++){
		if (arr[position+1]->atom_array[i] == 0){
			arr[position+1]->atom_array[i] =new  atom(1, hydrogen);//new
			hydrogen++;
			arr[position+1]->atom_array[i]->hydrogens[0] = arr[position+1];
		}
	}
}

void atom::alcinium(atom**arr, int position, int start1,int hydrogen){
	 int count = 0;
	while ((arr[position]->atom_array[count] != 0)&&(count<3)){
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
			arr[position]->atom_array[i] =new  atom(1, hydrogen);//new
			hydrogen++;
			arr[position]->atom_array[i]->hydrogens[0] = arr[position];
		}
	}
	for (int i = 0; i < 4; i++){
		if (arr[position + 1]->atom_array[i] == 0){
			arr[position + 1]->atom_array[i] =new  atom(1, hydrogen);//new
			hydrogen++;
			arr[position + 1]->atom_array[i]->hydrogens[0] = arr[position + 1];
		}
	}
}
void atom::print(atom**arr,int start,int w,int size){
		if ((w != size )&&(w!=start)){
			std::cout << ",";
		}
		std::cout << arr[w]->id[1] << arr[w]->counter << "(";
			if( (arr[w]->atom_array[0]->counter == arr[w]->atom_array[2]->counter) && (arr[w]->atom_array[0]->id[1]==arr[w]->atom_array[2]->id[1]) ){
				std::cout << "(triple)" << arr[w]->atom_array[0]->id[1] << arr[w]->atom_array[0]->counter << "," << arr[w]->atom_array[3]->id[1] << arr[w]->atom_array[3]->counter;
				std::cout << ")";
			}
			else if ( (arr[w]->atom_array[0]->counter == arr[w]->atom_array[1]->counter) && (arr[w]->atom_array[0]->id[1]==arr[w]->atom_array[1]->id[1]) ){
				std::cout << "(double)" << arr[w]->atom_array[0]->id[1] << arr[w]->atom_array[0]->counter << ",";
				std::cout << arr[w]->atom_array[2]->id[1] << arr[w]->atom_array[2]->counter <<", "<< arr[w]->atom_array[3]->id[1] << arr[w]->atom_array[3]->counter;
				std::cout << ")";

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
     if(arr[w]->atom_array[i]->id[1]=='h'){
       delete []arr[w]->atom_array[i]->hydrogens;
       }
    }
		std::cout << ")";
}
