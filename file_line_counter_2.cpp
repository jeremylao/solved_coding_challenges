#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]){
	
	int number_of_lines = 0;
	int ch;
	
	
	if(argc == 1){
		std::cout<< "There is one output" << std::endl;
	}
	
	else if(argc ==2 ){
		std::cout<< "There is two outputs and hopefully and input file" << std::endl;
	}
	
	FILE* input_file;
	
	input_file = fopen(argv[1],"r");
	
	while(EOF != (ch = getc(input_file))){
		if('\n' == ch){
			++number_of_lines;
			std::cout<< "hi" << std::endl;
		}
	}
	
	std::cout<< "num lines is: " << number_of_lines << std::endl;
	/*
	std::ifstream input_file (argv[1]);
	
	if(!input_file.is_open()){
		std::cout<< "Could not open file" << std::endl;
	}
	else if(input_file.is_open()){
		std::cout<< "is open" <<std::endl;
	}*/
	
	
	
	return 0;
}