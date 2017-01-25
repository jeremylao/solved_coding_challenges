#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

//get first number input
//create a loop with that number
//read each tree/name and store into a map
//if it doesn't exist, then create a new entry
//if it already exists, then increment the count

//map pairing: name, count

int main(){
	
	int iterations; int total =0; int j_loop = 0;
	string tree_name; string temp_string; string empty_line;
	
	vector<string> output_string (10000);
	vector<double> output_percentage (10000);
	
	cin >> iterations;

	getchar(); 
	getchar(); 
	
	for(int i =0; i<iterations; ++i){
		
		int temp_incr; int uniq_trees=0; int population=0; int percent_helper = 0; 
		
		map<string, double> tree_count;
		map<string, double>::const_iterator itr ;
		
		while(getline(cin, tree_name)){
			if(tree_name.empty()){
				break;
			}	
			if(!tree_count.count(tree_name)){
				++population;
				++uniq_trees;
				++total;
				tree_count[tree_name] = 1;
			}
			else if(tree_count.count(tree_name)){
				++population;
				temp_incr = 0;
				temp_incr = tree_count[tree_name];
				++temp_incr;
				tree_count[tree_name] = temp_incr;
			}
		}
	
		itr = tree_count.begin();
		
		for(int j = 0; j<uniq_trees; ++j){
			temp_string = itr->first;
			percent_helper = tree_count[temp_string];
			tree_count[temp_string] = percent_helper*100.0/population;
			++itr;
		}
		
		
		
		itr = tree_count.begin();
		
		for(j_loop = total - uniq_trees; j_loop <total; ++j_loop){
			output_string[j_loop] = itr->first; 
			output_percentage[j_loop] = itr->second; 
			++itr;
		}
		
		output_string[total] = "empty";
		++total;
	}
	
	for(int j = 0; j <total-1; ++j){
		
		if(output_string[j] != "empty"){
			cout << output_string[j] << " "; 
			printf("%.4f", output_percentage[j]); 
			cout << endl;
		}
		
		else{
			cout << endl;
		}
	
	}
		
	return 0;
}
