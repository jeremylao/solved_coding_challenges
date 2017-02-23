#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	
	int n;
	int temp = 0;
	cin >> n;
	
	int* blocks = (int*) malloc(sizeof(int) * (n+1));
	
	for(int i = 1 ; i<=n; ++i){
		cin >> blocks[i];
	}
	
	if(n % 2 == 0){
		for(int i = 1; i<=(n/2); ++i){
			if(i % 2 == 0){
			}
			else{
				temp = blocks[i];
				blocks[i] = blocks[n-i+1];
				blocks[n-i+1] = temp;
			}
		}
	}
	else{
		for(int i = 1; i<=(n/2); ++i){
			if(i % 2 == 0){
			}
			else{
				temp = blocks[i];
				blocks[i] = blocks[n-i+1];
				blocks[n-i+1] = temp;
			}
		}
	}
	
	for(int i = 1; i<=n; ++i){
		cout << blocks[i] << " ";
	}
	cout << endl;
	return 0;
}