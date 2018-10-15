#include <iostream>
#include <vector>

using namespace std;



bool isOdd(int k){
	if (k%2!=0)
		return true;
	else		
		return false;
}

bool isNotPrime(int candidate, vector<int>& newPrimesVector){
	if (isOdd(candidate)==true || newPrimesVector.size()==0){
		for (unsigned int i=0;i<newPrimesVector.size();i++){
			if (newPrimesVector[i]>1){
				if (candidate%newPrimesVector[i]==0){
					return true;
				}
			}
		}
		return false;
	}else 
		return true;
}

void printPrimes(vector<int>&newPrimesVector){
	if (newPrimesVector.size()<2)
		cout<< 1 << ": "<< newPrimesVector[0];
	else{		
		for (int i=0;i<newPrimesVector.size()-1;i++)
			cout<< i+1 << ": "<< newPrimesVector[i]<< ",\t";
		cout<< newPrimesVector.size() << ": "<< newPrimesVector[newPrimesVector.size()-1];
	}
	cout<<"\n"; 
}

int main()
{
	const int max=100;
	vector<int>primesVector;
	vector<int>oddPrimes;
	vector<int>evenPrimes;
	int sizeOfAllPrimes=0, sizeOfEvenPrimes=0, sizeOfOddPrimes=0;
	//allPrimes[0]=2;
	//evenPrimes=new int(2);
	for (int i=2;i<max;i++){
		if (isNotPrime(i,primesVector)==false){
			//addPrime(i,allPrimes,sizeOfAllPrimes++);		
			primesVector.push_back(i);
			//if (sizeOfAllPrimes==1)
			//	delete allPrimes;
			/*else*/ 
			if (isOdd(i))
				oddPrimes.resize(oddPrimes.size()+1);
			else	
				evenPrimes.resize(evenPrimes.size()+1);	
		}
	}
	cout << "All prime numbers until " << max << " are :\n";
	printPrimes(primesVector);
	
	if (evenPrimes.size()>0){
		if (evenPrimes.size()==1){
			for (int i=0,j=0;i<primesVector.size() && j<evenPrimes.size();i++)
				if (isOdd(primesVector[i])!=true)                           //ean einai swsto den xreiazetai if-else
					evenPrimes.push_back(primesVector[i]);
		}else{
			for (int i=0,j=0;i<primesVector.size() && j<evenPrimes.size();i++)
				if (isOdd(primesVector[i])!=true)
					evenPrimes.push_back(primesVector[i]);
		}
	} 
	cout << "\n\nAll even prime numbers until " << max << " are :\n";
	cout<< "1: "<< evenPrimes[0]<< "\t";
	if (oddPrimes.size()>0){
		for (int i=0,j=0;i<primesVector.size() && j<oddPrimes.size();i++)
			if (isOdd(primesVector[i])==true)
				oddPrimes.push_back(primesVector[i]);
	} 
	cout << "\n\nAll odd prime numbers until " << max << " are :\n";
	printPrimes(oddPrimes);	
	
	return 0;
}
