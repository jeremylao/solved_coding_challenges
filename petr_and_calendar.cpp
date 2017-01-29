#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int input_month, input_day;
	int output; 
	
	cin >> input_month;
	cin >> input_day;
	
	if(input_month == 1 || input_month == 3 || input_month ==5 || input_month == 7|| input_month ==8 || input_month ==10 || input_month == 12){
		if(input_day<=5){
			output = 5;
		}
		else {
			output = 6;
		}
	}
	else if(input_month == 4 || input_month ==  6 || input_month ==  9 || input_month ==  11){
		if(input_day <= 6){
			output = 5;
		}
		else{
			output = 6;
		}
	}
	else{
		if(input_day >1){
			output = 5;
		}
		else{
			output = 4;
		}
	}
	
	cout << output <<endl;
	
	
	return 0;
}





// 5 6 7
// 8 9 10 11 12 13 14 
// 15 16 17 18 19 20 21
// 22 23 24 25 26 27 28
// 29 30 31 32 33 34 35