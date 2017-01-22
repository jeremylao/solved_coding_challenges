#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

//greatest subarray
//add up the row, place the row into a TEMP array
//when finished populating the temp array, calculate the max sum, and compare to current max sum

int best(int size, int array[], int lookup[]){
	
	int temp=-214748364;
	
	if(size == -1){
		return -214748364;
	}
	
	temp = lookup[size];
	
	if(temp != -214748364){
		return temp;
	}
	
	if(temp < max(best(size-1,array,lookup) + array[size], array[size])) {
		temp = max(best(size-1,array,lookup) + array[size], array[size]);
	}

	lookup[size] = temp;
	
	return temp;
}


int main (){
	
	int number_columns = 0; int number_rows = 0; 
	int right_column = 0; int left_column = 0; int row = 0;
	int *lookup, *vector;
	int temp_max=-214748364; int max=-214748364;
	
	cin >> number_columns;
	number_rows = number_columns;
	
	//initialize the 2d array
	int **array = (int**) malloc(sizeof(int*) * number_columns);
	
	for(int i = 0; i < number_rows; ++i){
		array[i] = (int*) malloc(sizeof(int) * number_rows);
	}
	
	for(int i = 0; i<number_rows; ++i){
		for(int j = 0; j<number_columns; ++j){
			cin >> array[i][j] ;
		}
	}
	
	//array is populated, now code a way to iterate through each sub array:

	//1) For each column
	//2) Try each combination of columns where Starting Point (left is fixed) and various end points (right) are tried
	//3) for each row, add the sum of each and store into a temp array
	
	for(left_column = 0; left_column < number_columns; ++left_column){
		lookup = (int*) malloc(sizeof(int) * number_rows);
		vector = (int*) malloc(sizeof(int) * number_rows);
		for (int i = 0 ; i<number_rows; ++i){
			lookup[i] = -214748364;
			vector[i] = 0;
		}
		
		for(right_column = left_column; right_column < number_columns; ++right_column){
			
			lookup = (int*) malloc(sizeof(int) * number_rows);
			for (int i = 0 ; i<number_rows; ++i){
				lookup[i] = -214748364;
			}
			
			for(int i = 0 ; i<number_rows; ++i)
				vector[i] = vector[i] + array[i][right_column];
			
			temp_max = best(number_rows-1, vector, lookup);
			
			
			for (int i = 0 ; i<number_rows; ++i){
				if(temp_max < lookup[i])
				temp_max = lookup[i];
			}
			
			
			if(temp_max>max){
				max = temp_max;
			}
				
			
		}
	}
	
	cout << max << endl;
	
	return 0;
}