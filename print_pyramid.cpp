#include <iostream>


int main(){
	
	int input_digit;
	int incrementer;
	int padding;
	
	std::cout<<"How high do you want your pyramid to be?  "<<std::endl;
	std::cin>>input_digit;
	std::cout<<"this is the number: " << input_digit << "  that you inputted!" << "\n" ;
	
	for (int i = 0; i<input_digit; ++i){
		incrementer = (i+1)*2;
		padding = input_digit - (i + 1);
		
		for(int m = 0; m<(padding+1); ++m){
			std::cout<<" ";
		}
		
		for(int j = 0; j< incrementer ; ++j){
			std::cout<<"*";
		}
		
		
		std::cout<< "\n";
	}
	
	
	return 0;
}