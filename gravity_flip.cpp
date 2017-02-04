#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	
	
	int columns;
	cin >> columns;
	
	int *array = (int*) malloc(sizeof(int) * columns);
	int *output = (int*) malloc(sizeof(int) * columns);
	
	for(int i = 0; i<columns; ++i){
		
		cin >> array[i];
	}
	
	int cur_col;
	int nex_col;
	int excess;
	
	
	for(int j = 1; j<columns; ++j){
		
		for(int i = 0; i < columns-1; ++i){
			if(array[i] > array[i+1]){
				excess = array[i];
				array[i] = array[i+1];
				array[i+1] = excess;
			}
		
		}
	}
	
	
	for(int i = 0; i< columns; ++i){
		cout << array[i] << " ";
	}
	
	cout << endl;
	
	
	
	return 0;
}