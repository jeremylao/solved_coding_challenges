#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<stack>

using namespace std;


int main(){

	int cases;
	cin >> cases;
	int* case_array = (int*) malloc(sizeof(int) * cases);
	
	for(int z = 0; z<cases; ++z){

	int left, right;
	cin >>left >> right;

	stack<int> left_num;
	stack<int> right_num;
	
	int divleft = left;
	int divright = right;
	int left_height= 0;
	int right_height = 0;
	
	left_num.push(divleft);
	right_num.push(divright);
	
	while(divleft != 1){
		divleft = divleft/2;
		left_num.push(divleft);
		++left_height;
	}
	while(divright != 1){
		divright = divright/2;
		right_num.push(divright);
		++right_height;
	}
	int left_counter = 0;
	int	right_counter = 0;
	
	while(left_num.size() > 0 || right_num.size() > 0){
		if(left_num.size() == 0  && right_num.size() != 0){
			++right_counter;
			right_num.pop();
		}
		else if(right_num.size() == 0 && left_num.size() != 0){
			++left_counter;
			left_num.pop();
		}
		else if(left_num.top() == right_num.top()){
			left_num.pop();
			right_num.pop();
		}
		else{
			if(left_num.size() != 0){
				++left_counter;
				left_num.pop();
			}
			if(right_num.size() != 0 ){
				++right_counter;
				right_num.pop();
			}
		}
		
	}
	//cout << left_counter + right_counter << endl;
	case_array[z] = left_counter + right_counter;
	
	}
	
	for(int i = 0; i<cases ; ++i){
		cout << case_array[i] << endl;
	}
}