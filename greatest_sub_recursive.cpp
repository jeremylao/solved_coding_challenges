#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int best(int size, int array[], int lookup[]){
	
	int temp;
	
	if(size == -1){
		return 0;
	}
	
	temp = lookup[size];
	
	if(temp != -10000){
		return temp;
	}
	
	if(temp < max(best(size-1,array,lookup) + array[size], array[size])) {
		temp = max(best(size-1,array,lookup) + array[size], array[size]);
	}
	lookup[size] = temp;
	
	return temp;
}


int main (){
	

	int array[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int lookup[9];
	
	for (int i = 0 ; i<9; ++i){
		lookup[i] = -10000;
	}
	int result ; 
	result = best(8, array, lookup);
		
	
	for (int i = 0 ; i<9; ++i){
		if(result < lookup[i])
			result = lookup[i];
	}

	
	cout << "Result: " << result << endl;
	
	return 0;
}