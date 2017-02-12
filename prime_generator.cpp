#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stack>

using namespace std;


int is_not_prime(int number){
	int sqr;
	sqr = sqrt(number);
	if(number == 2){
		return 0;
	}
	else if(number%2 ==0 || number == 1){
		return 1;
	}
	else{
		for(int i = 2; i<=sqr; ++i){
			if(number % i == 0){
				return 1;
			}
		}
		return 0;
	}
}

int main() 
{ 
	int iterations, start, end;
	int prime_flag;
	
	cin >> iterations;
	
	int *start_number = (int*) malloc(sizeof(int) * iterations);
	int *end_number = (int*) malloc(sizeof(int) * iterations);
	
	for(int i = 0; i<iterations; ++i){
		cin >> start_number[i];
		cin >> end_number[i];
	}
	int k = 0;
	for(int j = 0; j<iterations; ++j){
		
		start = start_number[j];
		end = end_number[j];
		
		for(k = start; k<=end; ++k){
		
			prime_flag = is_not_prime(k);
			if(prime_flag==0){
				cout << k << endl;
			}
		}
		cout << endl;		
	}
} 