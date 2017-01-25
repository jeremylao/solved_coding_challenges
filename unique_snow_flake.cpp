#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int main(){
	
	int cases = 0; int num_flakes = 0; int unique_flag = 1;
	
	vector<uint64_t> output_vector (10000);
	vector<uint64_t> snowflake_array (1000001);
	stack<int> index_stack ;
	
	map<uint64_t, int> flake_map;
	map<uint64_t, int>::const_iterator itr ;
	
	cin >> cases;
	
	for(int i = 0; i < cases; ++i){
		
		int collision_pointer = 0; int start = 0; 
		uint64_t flake_number = 0; int incr = 0;
		flake_map.clear();
		
		cin >> num_flakes;
		
		for(int j = 0; j < num_flakes; ++j){
			cin >> snowflake_array[j]; 
		}
	
		snowflake_array[num_flakes] = -1;
		
		while(snowflake_array[collision_pointer] != -1){
			cout << "in while "<< " collision_pointer = " << collision_pointer << endl;
			cout << " start " << start; 
			
			index_stack.push(start);
			
			for(int j = start; j < num_flakes; ++j){
			
				flake_number = snowflake_array[j]; 
			
				if(flake_map.count(flake_number)==0){
					flake_map[flake_number] = 1;
				}
			
				else if(flake_map.count(flake_number)){
					
					int temp = start;
					
					while(flake_number != snowflake_array[start]){
						++start;						
					}
					
					index_stack.push(start);
					index_stack.push(j);
					start = ++start;
					
					flake_map.clear();
					flake_map[snowflake_array[start]] = 1;
					break;
				}
				
				collision_pointer = j+1;
				
			}
		
		}
	
	
	
	cout << endl;
	}
	
	for(int i = 0 ; i< index_stack.size(); ++i){
		
		cout << index_stack.top() << endl;
		index_stack.pop();
	}
	
	
	//int output = 0;
	//for(int k = 0 ; k < cases; ++k){
		
	//	cout << output_vector[k] << endl;
		
	//}
	
	return 0;   
}
