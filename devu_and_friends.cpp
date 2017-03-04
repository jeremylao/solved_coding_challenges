#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++)
      {
	key = arr[i];
	j = i-1;
 
	while (j >= 0 && arr[j] > key)
	  {
	    arr[j+1] = arr[j];
	    j = j-1;
	  }
	arr[j+1] = key;
      }
}


int main(){

  int test_cases;
  int friends;
  int day_of_party;
  
  cin >> test_cases;
  
  int* cases_array = (int*) malloc(sizeof(int) * test_cases);
  
  for(int i = 0; i<test_cases; ++i){
    cin >> friends;
    int* friend_array = (int*) malloc(sizeof(int) * friends);
    
    for(int j = 0; j<friends; ++j){
      cin >> friend_array[j];
    }
    insertionSort(friend_array, friends);
    int unique_counter;
    if(friends >0){
      unique_counter = 1;
    }
    else{
      unique_counter = 0;
    }
    for(int z=1; z<friends; ++z){
      if(friend_array[z-1] != friend_array[z]){
	++unique_counter;
      } 
    }
    cases_array[i] = unique_counter;
    free(friend_array);
  }

  for(int i = 0; i<test_cases; ++i){
    cout << cases_array[i] << endl;
  }


}
