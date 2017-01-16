#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <algorithm>

using namespace std;

struct reg {
	reg(): name(0), increment(0), time(0) {}
	int name, increment, time;
};


bool by_time(reg lhs, reg rhs) {

	if(lhs.time == rhs.time){
		return lhs.name < rhs.name;
	}
	else
		return lhs.time < rhs.time; 
}

	
bool by_name(reg lhs, reg rhs) { return lhs.name < rhs.name; }



void insertion_sort (reg **arr, int length){
	 	int j, temp, temp_reg, temp_inc;
		reg *reg_temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		
		while (j > 0 && arr[j]->time < arr[j-1]->time ){
			  
			  reg_temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = reg_temp;
			  j--;
			 
			  
			  }
		}
}


int main(){
	
	int total_number = 0;
	string temp;
	reg array [10000];
	
	
	while(temp != "#"){
		
		int *register_number; int *increment;
		register_number = (int*) malloc(sizeof(int));
		increment = (int*) malloc(sizeof(int));
		
		reg reg_1; 
		
		cin >> temp;
		
		if(temp == "#"){
			break;
		}
		
		cin >> *register_number;
		cin >> *increment; 
		
		
		reg_1.name = *register_number;
		reg_1.increment = *increment;
		reg_1.time = *increment;
		
		array[total_number] = reg_1;
		++total_number;
	}
	
	sort(array, array+total_number, by_time);
		
	int user_input = 0; int touched = 0;  int incrementer = 0;
	cin >> user_input; 
	
	
	while(touched < user_input){
		incrementer = array[0].time;
		if(incrementer == array[0].time){
			
			array[0].time = array[0].time + array[0].increment;
			cout << array[0].name << endl;
			sort(array, array+total_number, by_time);
			++touched;
		}
		++incrementer;
	}
	
	for(int i = 0; i<total_number; ++i){
	
	}
		
	return 0;
}