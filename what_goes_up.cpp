#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <fstream>
#include <stack>
#include <time.h>


using namespace std;

	

int main(int argc, char** argv){
	
	//clock_t start, end;
	string input;
	int count=0;
	int input_line[100000];
	
	//start = clock();
	
	int lookup_table[100000];
	int seq_count = 1;
	int last; 
	int temp_max=0;
	int temp_z = 0;
	int table_count[100000];
	int count_index = 0;
	int max_index = 0;
	int max_test = 0;
	int j = 0;
	//for(int j = 0; j<count; ++j){
	getline(cin, input);
	while(!input.empty()){
		input_line[j] = stoi(input);
		lookup_table[j] = 1;
		if(input_line[j] > input_line[last] ){
			lookup_table[j] = lookup_table[last]+1;
			max_test=max(lookup_table[j],max_test);
			last = j;
		}
			
		else if(input_line[j] <= input_line[last]){
			for(int z = j-1; z>=0; --z){
				if(input_line[z]<input_line[j]){
					temp_max = max(lookup_table[z]+1, temp_max);
					lookup_table[j] = temp_max;
					temp_z = max(temp_z, last);
					last = temp_z;
					max_test = max(temp_max, max_test);
				}
			}
		}
		temp_max = 0;
		++j;
		++count;
		getline(cin, input);
	}
	max_index = max_test;
		
	cout << max_index << endl;
	cout << "-" << endl;
	stack<int> output_stack;
	
	int output_table[100000];
	int print_count = 0;
	count = j;
	for(int k = count; k>=0 ; --k){
		if(lookup_table[k] == max_index){
			output_table[max_index] = input_line[k];
			--max_index;
			++print_count;
		}
		if(max_index == 0){
			break;
		}
	}
	
	//ofstream output_file(argv[1]);
	for(int i = 1; i<=print_count; ++i){
		cout << output_table[i] << endl;
	}
	
	//end = clock();
	//cout << "Time required for execution: " << (double)(end-start)/CLOCKS_PER_SEC << " seconds." << "\n\n";
	
	return 0;
}
