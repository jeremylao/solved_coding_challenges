#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>

using namespace std;

void insertion_sort (int *arr, int length){
	 	int j, temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		
		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
		}
}

int main(){
	
	int runs=0; int size; int* input_array; int total = 0; int running_cost = 0; int local_size = 0;
	vector<int> output_vector (100000);
	
	cin >> size;
	
	while(size != 0){
		
		input_array = (int*) malloc(sizeof(int) * size);
			
		for(int i = 0; i <size ; ++i){
			cin >> input_array[i];
		}
		local_size = size;
		
		insertion_sort(input_array, size);
		
		while(local_size >= 2){
				
			total = input_array[0]+input_array[1];
			running_cost = running_cost + total;
			input_array[1] = total;
			--local_size;
			//cout << "Total: " << total << endl;
			
			for (int i = 0; i<local_size; ++i){
				input_array[i] = input_array[i+1];
			}
			
			insertion_sort(input_array,local_size);
			total = 0;
			
		}
				
		
		output_vector[runs] = running_cost;
		
		++runs;
		free(input_array);
		cin >> size;
		running_cost = 0;
		total = 0;
		
	}
	
	for(int i = 0; i<runs; ++i){
		cout << output_vector[i] << endl;
	}
	
	
	return 0;
}