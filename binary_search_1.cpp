#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


int binary_search(int array[], int start, int end, int search){
	
	int begin; 
	int mid;
	int last;
	
	begin = start;
	mid = (start + end) / 2;
	last = end;
	
	if(array[mid] == search){
		
		return mid;
	}
	
	else if(array[mid]>search){
		
		binary_search(array,begin, mid, search);
		
	}
	else 
		binary_search(array, mid+1,end, search);
}


int main(){
	
	int array[16] = {5,9,23,43,56,62,87,98,100,123,145,167,223,263,345,367};
	int find = 62;
	int what_index;
	
	what_index = binary_search(array,0,15,find);
	
	std::cout << what_index << " ";
	
	std::cout << std::endl;
	
	return 0;
}