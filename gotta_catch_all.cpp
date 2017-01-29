#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>


//read string from input

//if the input from the string is the next letter for balubasar, then advacne balubasar pointer, 

//if you make the complete word, then advance balubasar count

//Bulbasaur

using namespace std;


int main(){
	
	string magic_word = "Bulbasaur";
	string input;
	string reference_point;
	
	
	int total_words = 0; int ref_index = 0;
	int B = 0;
	int u = 0;
	int l = 0;
	int b = 0;
	int a = 0;
	int r = 0;
	int s = 0;
	
	getline(cin, input);
	
	for(int i = 0; i<input.length(); ++i){
		
		if(ref_index==9){
			++total_words;
			ref_index = 0;
		}
		
		if(input[i] == 'B'){
			
			++B;
		}
		else if(input[i] == 'u'){
			++u;
		}
		else if(input[i] == 'l'){
			++l;
		}
		else if(input[i] == 'b'){
			++b;
		}
		else if(input[i] == 'a'){
			++a;
		}
		else if(input[i] == 'r'){
			++r;
		}
		else if(input[i] == 's'){
			++s;
		}
	
	}
	int temp;
	
	temp = min(B,l);
	temp = min(temp, b);
	temp = min(temp, s);
	temp = min(temp, r);
	temp = min(temp, a/2);
	temp = min(temp, u/2);
	
	cout << temp << endl; 
	
}