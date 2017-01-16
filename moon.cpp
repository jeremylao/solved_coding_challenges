#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;


int main(){

	
	int size = 0;
	
	cin >> size;
	
	int array[92];
	
	for(int i = 0 ; i< size; ++i){
		cin >> array[i];
	}

	
	
	if(array[size-1] == 15){
		cout << "DOWN";
	}
	
	else if(array[size-1]==0){
		cout << "UP";
		
	}
	
	else if(size == 1){
		cout << -1 << endl;
	}
	
	else if(array[size-1] > array[size-2]){
		cout << "UP";
	}
	else if(array[size-1] < array[size-2]){
		cout << "DOWN";
	}
	
	cout << endl;

	return 0;
}