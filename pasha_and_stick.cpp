#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	
	//stick length n, perform 3 cuts to get four parts of the stick
	
	int length_stick;
	cin >> length_stick;
	
	if(length_stick % 4 == 0){
		cout << length_stick/4 -1 << endl;
	}
	else if(length_stick < 6){
		cout << 0 << endl;
	}
	else if (length_stick % 4 == 2){
		cout << length_stick/4  << endl;
	}
	else if(length_stick % 4 == 1 || length_stick % 4 == 3){
		cout << 0 << endl;
	}
	return 0;
}