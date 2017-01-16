#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>


int input_jack = -1;
int input_jill = -1;

//write a binary search
//iterate through one array, and binary search that number on the other array

void binary_search(int array_search[], int value_search, int *incrementer){
	int low = 0; int high = input_jill -1;
	int mid = 0;
	
	while(low <= high){
		mid = (low + high) /2;
	
		if(array_search[mid] == value_search){
			++*incrementer;
			return;
		}
		else if(array_search[mid] > value_search){
			high = mid -1;
		}
		else if (array_search[mid] < value_search){
			low = mid + 1;
		}
	}
	
	return;
}


int main(){
	
	int *incr = (int*) malloc(sizeof(int)); int case_count=0;
	*incr = 0;
	
	std::vector<int> output_vector (100000);
	
	std::cin >> input_jack;
	std::cin >> input_jill;
	
	if(input_jack == 0 && input_jill == 0){
		std::cout << 0 << std::endl;
	}
	
	while(input_jack != 0 && input_jill != 0){
	
		*incr = 0;
		int* jack = (int*) malloc(sizeof(int) * input_jack);
		int* jill = (int*) malloc(sizeof(int) * input_jill);
	
		for(int i = 0 ; i<input_jack; ++i){
			std::cin >> jack[i];
		}
		
		for(int i =0; i<input_jill; ++i){
			std::cin >> jill[i];
		}
	
		if(input_jack>= input_jill){
			for(int i=0; i<input_jack; ++i){
				binary_search(jill, jack[i], incr);
			}
		}
		else {
			for(int i=0; i<input_jack; ++i){
				binary_search(jack, jill[i], incr);
			}
		}
	
		output_vector[case_count] = *incr;
		++case_count;
		
		std::cin >> input_jack;
		std::cin >> input_jill;
		
		free(jack);
		free(jill);
	
	}
	
	for(int j = 0 ; j<case_count; ++j){
		std::cout << output_vector[j] << std::endl;
	} 
	
	
	return 0;
}