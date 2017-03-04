#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;


int main(){
	
	int words, seconds; 
	cin >> words;
	cin >> seconds;
	int* word_array = (int*) malloc(sizeof(int) * words);
	for(int i = 0 ; i<words; ++i){
		cin>>word_array[i];
	}
	int on_screen = 1;
	int temp = 0;
	
	for(int j = 1; j<words; ++j){
		temp = word_array[j] - word_array[j-1]; //cout << "hi";
		if(  temp <= seconds ) {
			++on_screen;
		} 
		else{
			on_screen = 1;
		}
	}
	cout << on_screen << endl;
}


