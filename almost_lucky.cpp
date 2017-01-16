#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>


using namespace std;

bool is_lucky(int input){
	
	int counter = 0;
	int if_count = 0;
	
	while(input > 0){
		
		if(input%10 == 7 || input%10 == 4){
			++if_count;
		}
		input = input / 10;
		++counter;
	}
	if(counter == if_count){
		return true;
	}
	return false;
}


int main(){
	
	int test;
	bool lucky = false;
	
	cin >> test;
	
	if (test > 1000  || test <= 0){
		cout << "NO" << endl;
		return 0;
	}

	if (test % 4 == 0 || test % 7 == 0 ){
		cout << "YES" << endl;
		return 0;
	}
	
	for(int i = 4; i<= test; ++i){
		if(is_lucky(i)&& test%i == 0){
			lucky = true;
		}
	}
	
	
	if(lucky){
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
}