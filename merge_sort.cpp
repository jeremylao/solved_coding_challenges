#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(){
	
	int array[10];
	int output;
	srand(time(NULL));
	output = rand()%1000;
	int test = 234;
	
	for (int i = 0; i<10; ++i){
		
		array[i] = rand()%100;
		
	}
	
	for(int j = 0; j<10; ++j){
		
		std::cout << array[j] << " ";
		
	}
	
	std::cout << std::endl;
	
	
	int sentinel; 
	int temp;
	
	for(int m = 10; m>0; --m){
		
		for(int n=0; n<m; ++n){
			
			if(array[n]>array[n+1]){
				temp = array[n];
				array[n] = array[n+1];
				array[n+1] = temp;
			}
		}
		
	}
	
	for(int j = 0; j<10; ++j){
		
		std::cout << array[j] << " ";
		
	}
	
	return 0;
	
}