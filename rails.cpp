#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>

using namespace std;


int main(){
	
	int number; 
	
	queue<string> result_queue;
	
	cin >> number;
	
	while(number != 0){
		
		int temp;
		cin >> temp;
		
		while(temp != 0){
			
			
			queue<int> start_queue;
			stack<int> holding_stack;
			queue<int> finish_queue;
	
			for(int i = 0; i<number; ++i){
				start_queue.push(i+1);
			}
	
			
			int station =0;
	
			for(int i = 0; i<number-1; ++i){
				finish_queue.push(temp);
				cin >> temp;
			}
	
			int lock = 0;
			int temp2;

	
			while(lock != 1){
				if(finish_queue.empty()){
					result_queue.push("Yes");
					//cout << "WORKS " << endl;
					//return 0;
					lock = 1;
				}
		
				else if (!start_queue.empty() && finish_queue.front() == start_queue.front()){
					finish_queue.pop();
					start_queue.pop();
				}
		
				else if(!holding_stack.empty() && holding_stack.top() == finish_queue.front()){
					holding_stack.pop();
					finish_queue.pop();
				}
		
				else if(start_queue.empty()){
			
					if(!holding_stack.empty() && holding_stack.top() != finish_queue.front()){
						//cout << "doesn't work " << endl;
						//return 0;
						lock = 1;
						result_queue.push("No");
					}
			
					else if(!holding_stack.empty() && holding_stack.top() == finish_queue.front()){
						finish_queue.pop();
						holding_stack.pop();
					}
				} 
		
				else if(!start_queue.empty()){
					temp2 = start_queue.front();
					start_queue.pop();
					holding_stack.push(temp2);
				}
		
				else if(holding_stack.top() != finish_queue.front() && start_queue.front() != finish_queue.front()){
					lock = 1;
				}

				 
			}
			
			cin >> temp;
			
		}
			
		cin >> number;
		result_queue.push("");
	}
	
	while(!result_queue.empty()){
		cout << result_queue.front() << endl;
		result_queue.pop();
	}
	
	
	return 0;
}