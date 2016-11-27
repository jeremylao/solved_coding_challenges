#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <sstream>


//turn infix into post fix evaluation ((t|f)&(f|f))


using namespace std;



bool evaluator(bool left, bool right, char expression){
	
	if(expression == '|'){
		return (left || right);
	}
	else if(expression == '&'){
		return (left && right);
	}
	
}

bool naughter(bool to_naught){
	return (!to_naught);
}

bool assign_bool(char letter, string input){
	if (input[input.length()-1] == 't'){
		return true;
	}
	else{
		return false;
	}
}



int main(){
	
	bool left;
	bool right;
	bool result;
	char operation;
	char temp;
	char final_compare;
	char initial_num;
	
	string input;
	
	cout  << "Boolean Evaluator Tool" << endl;
	cout << "Enter a boolean expression and what you think the answer is" << endl;
	cout << "The tool will indicate correct or incorrect answer to the expression" << endl;
	
	cout << endl;
	
	cout << "Legal Input: 't' for true, 'f' for false, '!' for not, '|' for or, '&' for and" << endl;
	
	cout << "Parens need to be used for proper evaluation, and expressions inside parens will be evaluated first" <<endl;
	
	cout << endl;
	
	cout << "Enter number of expressions to evaluate: " << endl;
	
	int num_loops = 0;
	
	getline(cin, input);
	
	istringstream buffer(input);
	buffer >> num_loops;
	
	string output[num_loops];
	
	if (num_loops > 10000){
		exit(EXIT_FAILURE);
	}
	
	for(int j = 0 ; j<num_loops; ++j){
	
	stack<bool> bool_stack;
	stack<char> eval_stack;
	
	getline(cin, input);
	
	for(int i = 0; i<input.length(); ++i){
		temp = input[i];
		
		if(temp == '(' or temp == ' '){
			continue;
		}
		
		else if(temp == 't' or temp == 'f'){
			if(temp == 't'){
				bool_stack.push(true);
			}
			else if(temp == 'f'){
				bool_stack.push(false);
			}
		}
		else if(temp == '!'){
			eval_stack.push('!');
		}
		else if(temp == '|' or temp == '&'){
			if(temp == '|'){
				eval_stack.push('|');
			}
			else if(temp == '&'){
				eval_stack.push('&');
			}
		}
		else if(temp == ')'){
			
			if(eval_stack.top() == '|' or eval_stack.top() == '&'){
	
				left = bool_stack.top();
				bool_stack.pop();
	
				right = bool_stack.top();
				bool_stack.pop();
	
				operation = eval_stack.top();
				eval_stack.pop();
	
				result = evaluator(left,right,operation);
				
				bool_stack.push(result);
				
				
				if(!eval_stack.empty() && eval_stack.top() == '!'){
					result = naughter(bool_stack.top());
				bool_stack.pop();
				bool_stack.push(result);
				eval_stack.pop();
				}
				
				
				}
			
			else if(!eval_stack.empty() || eval_stack.top() == '!'){
			//	cout << eval_stack.top() << endl;
			//	cout << bool_stack.top() << endl;
				result = naughter(bool_stack.top());
				bool_stack.pop();
				bool_stack.push(result);
				eval_stack.pop();
			}
		}
		else if( temp == '='){
			final_compare = input[input.length() -1];
			result = assign_bool(final_compare, input);
			
			if (bool_stack.top() == result){
				output[j] = "Correct";
			}
			else{
				output[j] =  "Incorrect";
			}
		}
		
	}
	
	}
	
	for (int m = 0; m<num_loops; ++m){
		cout << (m+1) << ": " << output[m] << endl;
	}
	
	return 0;
}