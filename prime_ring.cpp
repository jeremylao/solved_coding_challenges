#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>

#define PRINT1D print_1d_array

void initialize_array(int** array, std::map<int,int> prime_map, int n){
	for(int i = 1; i <=n; ++i){
		for(int j = 1; j <=n; ++j){
			if(prime_map.count(i+j)){
				array[i][j] = 1;
			}
			else{
				array[i][j] = 0;
			}
		}
	}
	for(int i = 1; i <=n; ++i){
		if(prime_map.count(i+1)){
			array[i][n+1] = 1;
		}
		else{
			array[i][n+1] = 0;
		}
	}
}

void mark_column(int** array, int column, int n){
	for(int row = 1; row <=n; ++row){
		for(int col = 1; col <= n; ++ col){
			if(col == column){
				array[row][col] = 0;
			}
		}
	}
}

void reset_column(int** array, int column, int n, std::map<int,int> prime_map){
	for(int row = 1; row <=n; ++row){
		for(int col = 1; col <= n; ++ col){
			if(col == column){
				array[row][col] = prime_map.count(row+col);
			}
		}
	}
}

void print_1d_array(int* array, int N){
	for(int i = 1; i<=N; ++i){
		if(i == N){
			std::cout << array[i];
		}
		else{
			std::cout << array[i] << " ";
		}
	}
	std::cout << std::endl;
}

void prime_ring(int** array, int* buffer, int row, int* idx, int N, std::map<int, int> prime_map){

	if(*idx >= N && prime_map.count(buffer[N] +1) == 1){
		PRINT1D(buffer, N);
	}
	
	else{
		for(int i = 2; i<= N; ++i){
			
			if(array[row][i] == 1){
				++*idx;
				buffer[*idx] = i;
				mark_column(array, i, N);
				prime_ring(array, buffer, i, idx, N, prime_map);
				buffer[*idx] = 0;
				--*idx;
				reset_column(array, i, N, prime_map);
			}
		}
	}
}

int main(){
	
	std::map<int,int> prime_map;
	prime_map[3]; prime_map[5]; prime_map[7]; prime_map[11]; prime_map[13];
	prime_map[31]; prime_map[29]; prime_map[23]; prime_map[19]; prime_map[17];
	
	std::string user_input;  
	int input; int input_count = 0;
	int output[100];
	
	while(getline(std::cin, user_input)){
		
		if(user_input.empty()){
			break;
		}
		output[input_count] = std::stoi(user_input);
		++input_count;
	}
	
	for(int z = 0; z < input_count; ++z){
	
	input = output[z];
	
	
	if(input == 5 || input == 9 || input == 13){
		printf("Case %d:\n", z+1);
	}
	else{
	int count = 1; int *index = (int*) malloc(sizeof(int));
	*index = 1;
	int** prime_table;
	int* output_table;
	
	printf("Case %d:\n", z+1);
	++input;
	
	prime_table = (int**) malloc(sizeof(int*) * input);
	output_table = (int*) malloc(sizeof(int) * input);
	
	for(int i = 0; i<input ; ++i){
		prime_table[i] = (int*) malloc(input * sizeof(int));
	}
	
	initialize_array(prime_table, prime_map, input-1);
	
	output_table[1] = 1;
	
	prime_ring(prime_table, output_table, 1,index,input-1, prime_map);
	
	free(index);
	free(prime_table);
	free(output_table);
	}
	
	std::cout << std::endl;
	
	
	}
	
	return 0;
	
}


//