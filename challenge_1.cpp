#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main(){

	int number_strings;
	int number_rules;
	string rules[50];

	cin >> number_strings; 
	cout << "" << endl;

	for(int i = 0; i<=number_strings; ++i){
		string input;
		getline(cin, input);
		//cout << "index i is " << i << endl;
		rules[i] = input;
	}
        
        //cout << number_strings << endl;
        
        int number[50];

        cin >> number_rules;

        for(int j=0; j<number_rules; ++j){
                int inputnumrule;
                cin >> inputnumrule; //getline(cin, inputnumrule);
	        //cout << rules[inputnumrule] << endl;
                number[j] = inputnumrule;
        }

        for(int k=0; k<number_rules; ++k){       

	        if(1 <= number[k] && number[k] <= number_strings){
                  cout << "Rule " << number[k] << ": " << rules[number[k]] << endl;
		  
		}

		else if(number[k] <1 || number[k] >number_strings){
		  cout << "Rule " << number[k] << ": No such rule" << endl;  
		}

	}

        
return 0;

}


