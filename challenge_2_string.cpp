#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>


using namespace std;

int main(){

	int number_tests = 0;
	int result_array[5];
	
	
	cin>>number_tests;
	cin >> ws;
	//scanf("%d [^\n]", &number_tests);
	
	for(int m =0; m<number_tests; ++m){

		size_t initial = 1000;
		int  bytes_read = 1;
		int number_paid_characters = 0;
		
		char temp_char;
		int temp_int;
		int number_of_lines = 0;
		char line_new;
		string temp_string;
		
		//scanf("%d [^\n]", &number_paid_characters);
		cin>>number_paid_characters;
		cin >> ws;
	
		map<char, int> this_map;
  
		for(int i = 0; i<number_paid_characters; ++i){
			//scanf(" %c %d [^\n]", &temp_char, &temp_int);
			cin >> temp_char;
			cin >> temp_int;
			this_map[temp_char] = temp_int;
			cin>>ws;
		}
		
		cin >>number_of_lines;
		cin >> ws;
  
	//initialize the character arrays///////////////////////////////////////////////
		
		int cumulative_cost = 0;
		string user_input[number_of_lines];
		
		for(int j = 0; j <number_of_lines; ++j){
			getline(cin, user_input[j]);
		}
			
	
		for(int i = 0; i<number_of_lines; ++i){
			for(int j = 0; j<user_input[i].length(); ++j){
				cumulative_cost = this_map.find(user_input[i][j])->second + cumulative_cost;
			}	
		}
		result_array[m] = cumulative_cost;
		this_map.clear();
		for(int i=0; i<number_of_lines; ++i){user_input[i].clear();}
		
	}
	
	
	printf("\n");
	for(int i =0; i<number_tests; ++i){
		double cost_double = result_array[i];
		printf("%.2f$\n",cost_double/100);
	}
	printf("\n");
	
	
	
  return 0;
}