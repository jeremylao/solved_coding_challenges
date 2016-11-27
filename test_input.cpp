#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){

	const char *number_strings;
	
	int number_of_rules;
	int number_rules;

	char line_input[66];

	int rules[10];
	
	cin >> number_of_rules;
	cin >> ws;
	
	for(int i =0 ; i < number_of_rules ; ++i){
		cout << "hello" << endl;
		string input;
		getline(cin, input);
		cin >> ws;
	}

	
	return 0;
	
}