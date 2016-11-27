#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(){
	
	int array[10]; 
	
	for(int i=0; i<10; ++i){
		
		array[i] = i;
	}
	
	
	for(int j = 0; j<10; ++j){
		
		std::cout << array[j] << " "; 
	}
	
	std::cout << endl;
	
	
	
	
	
	
	
	
	return 0;
}