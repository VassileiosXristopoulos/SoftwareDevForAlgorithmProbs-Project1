#include "unions.h"
#include <iostream>
unions::unions(atom ***arr, int Num,int start,int total){
	numb = total;
	hydrogen = 0;
	/*for (int i = start; i < Num; i++){
		atom *test = new atom(4);
	 //arr[i] = new atom(4)
		arr[i] = (*test).p;
	}*/
	for (int i = start; i < Num; i++){
		new atom(4, arr, i);
	}
}


unions::~unions(){
}
void unions::alcanium(int start,int number,atom ***pt){
	int counter = 1;
/*atom **h = new atom*[(number - start) * 2 + 2];
	for (int i = 0; i < (number - start) * 2 + 2; i++){
		h[i] = new atom(1);
	}*/
	pt[start][0] = *pt[start + 1];  //first and last C connections 
	pt[number][0] = *pt[number - 1]; 
	for (int k = 1; k < 4; k++){//first and last C has 3 Hydrogens
		pt[start][k] = new atom(1,pt,k);
		//h[hydrogen] = pt[start];
		//hydrogen++;
		pt[number][k] = new atom(1, pt, k); 
		//h[hydrogen] = pt[number];
		//hydrogen++;
	}
	for (int i = start+1; i<number - 1; i++){ // C connections with each other
		pt[i][1] = *pt[i + 1];
		pt[i][0] = *pt[i - 1];
	}
	for (int i = start + 1; i < number - 1; i++){ //the rest of the hydrogen connections
		pt[i][2] = new atom(1, pt, i);
		//h[hydrogen] = pt[i];
		//hydrogen++;
		pt[i][3] = new atom(1, pt, i);
		//h[hydrogen] = pt[i];
		//hydrogen++;
	}
	/*for (int i = 0; i < hydrogen; i++){
		delete h[i];
	}
	delete[] h;*/
}

void unions::alcenium(int start, int number,atom ***pt){
/*atom **h = new atom*[(number - start) * 2];
	for (int i = 0; i < (number - start) * 2; i++){
		h[i] = new atom(1);
	}*/
	pt[start][0] = *pt[start + 1];  //double connections
	pt[start][1] = *pt[start + 1];
	pt[start + 1][0] = *pt[start];
	pt[start + 1][1] = *pt[start];
	

	pt[start][2] = new atom(1, pt, 0); //hydrogen connections for first C
	//h[hydrogen] = *pt[start];
	//hydrogen++;
	pt[start][3] = new atom(1, pt, 0);
	//h[hydrogen] = *pt[start];
	//hydrogen++;

	pt[start + 1][2] = new atom(1, pt, 0); //C and H connections for second C
	//h[hydrogen] = *pt[start];
	//hydrogen++;
	pt[start + 1][3] = *pt[start + 2];

	pt[number][0] = *pt[number - 1];  // C and H connections for last C 
	for (int k = 1; k < 4; k++){
		pt[number][k] = new  atom(1, pt, k); 
		//h[hydrogen] = *pt[number];
		//hydrogen++;
	}
	for (int i = start + 2; i < number - 1; i++){ // C connections with each other
		pt[i][1] = *pt[i + 1];
		pt[i][0] = *pt[i - 1];
	}
	for (int i = start + 2; i < number - 1; i++){ //the rest of the hydrogen connections
		pt[i][2] = new atom(1, pt, i);
		//h[hydrogen] = *pt[i];
		//hydrogen++;
		pt[i][3] = new atom(1, pt, i);
		//h[hydrogen] =*pt[i];
		//hydrogen++;
	}
	/*for (int i = 0; i < hydrogen; i++){
		delete h[i];
	}
	delete[] h;*/
}

void unions::alcinium(int start,int number,atom ***pt){
atom  **h = new atom*[(number - start) * 2 - 2];
	for (int i = 0; i < (number - start) * 2 - 2; i++){
		h[i] = new atom(1, pt, i);
	}
	for (int i = 0; i < 3; i++){  //ALL connections for first 2 C
		pt[start][i] = *pt[start + 1];
		pt[start + 1][i] = *pt[start];
	}
	pt[start][3] = new atom(1, pt, 0);
	//h[hydrogen] = *pt[start];
	//hydrogen++;

	for (int i = 1; i < 3;i++){ //connections for last C
		pt[number][i] = new atom(1, pt, i);   
		//h[hydrogen] = pt[number];
		//hydrogen++;
	}
	pt[number][0] = *pt[number - 1]; 


	for (int i = start + 2; i < number - 1; i++){ // the rest of the C connections with each other
		pt[i][1] = *pt[i + 1];
		pt[i][0] = *pt[i - 1];
	}
	for (int i = start + 2; i < number - 1; i++){ //the rest of the hydrogen connections
		pt[i][2] = new atom(1, pt, i);
		//h[hydrogen] = pt[i];
		//hydrogen++;
		pt[i][3] = new atom(1, pt, i);
		//h[hydrogen] = pt[i];
		//hydrogen++;
	}
	/*for (int i = 0; i < hydrogen; i++){
		delete h[i];
	}
	delete[] h;*/
}
/*void unions::print(int Ccounter, int hcounter, int number,int desmos){
	if (desmos == 1){
		for (int i = 1; i <= number; i++){

		}
	}
	else if (desmos == 2){

	}
	else if (desmos == 3){

	}
}*/

