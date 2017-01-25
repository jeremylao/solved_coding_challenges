#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

void insertion_sort (uint64_t arr[], int length){
	 	int j;
		uint64_t temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		
		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
		}
}

uint64_t converter(uint64_t arr[]){
	
	uint64_t to_convert;
	uint64_t converted = 0;
	uint64_t helper[5] = {1000000000000, 1000000000, 1000000, 1000, 1};
	
	for(int i = 0 ; i<5 ; ++i){
		converted = helper[i] * arr[i] + converted;
	}
	
	return converted;
}
int main(){
	
	int iterations = 0;
	cin >> iterations;
	uint64_t course_array[5];
	uint64_t temp;
	
	int test_number = 0;
	
	vector<int> max_vector (10000);
	
	map<uint64_t, int>::const_iterator itr ;
	
	while(iterations != 0){
		
		int uniq = 0;
		uint64_t course_number;
		int temp_incr;
		map<uint64_t, int > course_map;
		
		for(int i =0; i<iterations; ++i){

			for(int j = 0; j<5; ++j){
				cin >> course_number;
				course_array[j] = course_number;
			
			}
			
			insertion_sort(course_array, 5);
			
			temp = converter(course_array); 
			
			if(!course_map.count(temp)){
				++uniq;
				course_map[temp] = 1;
			}
			else if(course_map.count(temp)){
				temp_incr = 0;
				temp_incr = course_map[temp];
				++temp_incr;
				course_map[temp] = temp_incr;
			}
			
		}
		
		int max = 0;
		int pop_count=0;
		itr = course_map.begin();
	
		for(int j = 0; j < uniq; ++j){
			if(max < itr->second){
				max = itr->second;
			}
				++itr;
				//cout << "max is = " << max << endl;
		}	
		
		itr = course_map.begin();
		for(int k=0; k < uniq; ++k){
			if(max == itr->second){
				pop_count = itr->second + pop_count;
			}
			//cout << "itr -> second = " << itr->second << " pop_count = " << pop_count << endl;
			++itr;
		}
		
		max_vector[test_number] = pop_count;
		++test_number;
		
		cin >> iterations;
	}

	int temp_output = 0;
	
	for(int i = 0 ; i<test_number ; ++i){
		temp_output = max_vector[i];
		cout << temp_output << endl;
	}
	
	return 0;
}
