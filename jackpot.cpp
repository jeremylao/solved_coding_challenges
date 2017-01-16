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
	
	int number_elements = 0; int count = 0; vector<int> output_vector (100000);
	
	cin >> number_elements;
	
	while(number_elements != 0){
	
		int *array = (int*) malloc(sizeof(int) * number_elements);
		int *lookup = (int*) malloc(sizeof(int) * number_elements);
	
		for(int i = 0 ; i<number_elements; ++i){
			cin >> array[i];
		}
	
		for (int i = 0 ; i<number_elements; ++i){
			lookup[i] = -10000;
		}
	
		int result ; 
		result = best(number_elements-1, array, lookup);
		
	
		for (int i = 0 ; i<number_elements; ++i){
			if(result < lookup[i])
				result = lookup[i];
		}
		
		output_vector[count] = result;
		++count;
		
		cin >> number_elements;
	
	}
	
	for(int i = 0 ; i<count; ++i){
		if(output_vector[i] > 0){
			cout << "The maximum winning streak is " << output_vector[i] << "." << endl;
		}
		else{
			cout << "Losing streak." << endl;
		}
	}
	
	return 0;
}