#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//create a list of valid oranges by iterating through the orange list and keeping organges that are as big
//or smaller than the limit

//add up the legal organe vector, mod it by the throw_away, and return result

int main(){
	
	int num_oranges, max_size, throw_away, orange, answer;
	
	cin >> num_oranges;
	cin >> max_size; 
	cin >> throw_away;
	
	int run_sum = 0;
	answer = 0;
	
	for(int i = 0; i<num_oranges; ++i){
		cin >> orange;
		if(orange <= max_size){
			run_sum = run_sum + orange;
		}
		if(run_sum > throw_away){
			++answer;
			run_sum = 0;
		}
	}

	cout << answer << endl;
	
	
	return 0;
}