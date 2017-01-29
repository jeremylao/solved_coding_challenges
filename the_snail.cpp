#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;


struct snail_struct{
	
	int day;
	double day_climb;
	double height_well;
	double slide_night;
	double fatigue_factor;
	double initial;		
	double first_day_climb;
};

void update(snail_struct* snail, double result){
	
	//cout << " Initial Height: " << snail->initial  ;
	//cout << " Climbed: " << snail->day_climb ;
	if(result > snail->height_well){
		++snail->day;
	}
	else{
		++snail->day;
		snail->day_climb = max(snail->day_climb - snail->first_day_climb * (snail->fatigue_factor),0.0);
		snail->initial = result - snail->slide_night;
	}
	//cout << " Height after Climbing: " << result;
	//cout << " Height after sliding: " << snail->initial  <<endl;
	
}


int main(){

	int H, U, D, F;
	int counter=0;
	int *output = (int*) malloc(sizeof(int) * 10000);
	double *result_array = (double*) malloc(sizeof(double) * 10000);
	double *well_height = (double*) malloc(sizeof(double) * 10000);
	
	while(1){
	
		cin >> H;
		cin >> U;
		cin >> D;
		cin >> F;

		if(H == 0){
			for(int i = 0; i<counter; ++i){
				if(result_array[i] > well_height[i]){
					cout << "success on day " << output[i] << endl;
				}
				else{
					cout << "failure on day " << output[i] << endl;
				}
			}
			return 0;
		}

		snail_struct *snail  = (snail_struct*) malloc(sizeof(snail_struct) * 1);

		snail->day = 0;
		snail->height_well = H;
		snail->day_climb = snail->first_day_climb = U;
		snail->slide_night = D;
		snail->fatigue_factor = F/100.0;
		snail->initial = 0;

		double result;
		
		result = snail->day_climb + snail->initial;
		
		if(result > snail->height_well){
			update(snail, result);
			result_array[counter] = result;
			output[counter] = snail->day;
			well_height[counter] = snail->height_well;
			++counter;
		}
		
		else{
		
			update(snail, result);
		
			while(snail->initial <= snail->height_well && snail->initial >= 0.0){
			
				result = snail->initial + snail->day_climb;
			
				if(result > snail->height_well){
					update(snail, result);
					break;				
				}
			
				if(snail->initial <= 0){
					update(snail, result);
					break;
				}
			
				update(snail, result);
			
			}
			//cout << result << endl;
			result_array[counter] = result;
			output[counter] = snail->day;
			well_height[counter] = snail->height_well;
			++counter;
		
			//cout << result << endl;
			//cout << snail->day << endl;
		}
	}

	for(int i = 0; i<counter; ++i){
		if(result_array[i] > well_height[i]){
			cout << "success on day " << output[i] << endl;
		}
		else{
			cout << "failure on day " << output[i] << endl;
		}
	}
}