#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <set>
#include <vector>

using namespace std;

int is_palindrome(string test_pali){

	int i,j;
	i = 0;
	j = test_pali.length()-1;
	if(test_pali.length() % 2 == 1){  //odd
		while(test_pali[i] == test_pali[j]){
			if(i == j){
				return 1;
			}
			i = i+1;
			j = j-1;
		}
	
	}
	else{
		while(test_pali[i] == test_pali[j]){
			if( i+1 == j){
				return 1;
			}
			i = i+1;
			j = j-1;
		}
		
	}
	return 0;
}

int main(){

	string input;
	int count = 0;
	vector<int> num_palindromes (10000);
	vector<string> string_vector (10000);
	
	getline(cin, input);
	
	
	while(!input.empty()){
		
	//cin >> input;
	string temp;
	temp = "";
	
	set<string> already_done;
	
	for(int j = input.length(); j>0; --j){
		
		for(int i = 0; i<j; ++i){
			
			for(int z = i; z<j; ++z){
				//cout << input[z];
				temp = temp+input[z];
			}
			//cout << "TEMP: " << temp << endl;
			if(is_palindrome(temp) == 1){
				already_done.insert(temp);
			}
			//count = is_palindrome(temp) + count;
			//cout << " " << count << " ";
			temp = "";
		}
		//cout << endl;
	}
	
	string_vector[count] = input;
	num_palindromes[count] = already_done.size();
	++count;
	//cout << already_done.size() << endl;
	getline(cin, input);
	}
	
	
	for(int i = 0; i<count; ++i){
		cout << "The string '" << string_vector[i] <<"' contains " << num_palindromes[i] << " palindromes." << endl;
	}
	return 0;
}