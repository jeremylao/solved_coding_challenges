#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){

	int number_strings;
	int number_rules;
	string rules[64];
	int number[50];
	
	ifstream input_file("input.txt");	
	
	string line;	

	while(input_file.good()){
		
		getline(input_file,line);
		const char *temp_num = line.c_str();
		number_strings = std::atoi(temp_num);

		for(int i = 0; i<number_strings; ++i){
			string input;
			getline(input_file, input);
			rules[i] = input;
		}
		
		getline(input_file,line);
		temp_num = line.c_str();
		number_rules = std::atoi(temp_num);

		for(int j = 0; j < number_rules; ++j){
			getline(input_file,line);
		    temp_num = line.c_str();
			number[j] = std::atoi(temp_num);
		}


	}
	
		for(int k=0; k<number_rules; ++k){       

			if(1 <= number[k] && number[k] <= number_strings){
                cout << "Rule " << number[k] << ": " << rules[number[k]-1] << endl;
		  
		}

		else if(number[k] <1 || number[k] >number_strings){
		  cout << "Rule " << number[k] << ": No such rule" << endl;  
		}
		}

        
return 0;

}


