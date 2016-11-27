#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


int read_string(std::string input_string){
	
	int number_words = 0;
	int i = 0;
	
	while (i < input_string.size()+1){
		
		if(isalpha(input_string[i])){
			++number_words;
			while(i < input_string.size() && isalpha(input_string[i])) ++i;
		}
		else{
		
		++i;
		}
	}
	
	return number_words;
}


int main(int argc, char *argv[]){
	
	int number_of_lines = 1;
	int number_a = 0;
	int ch;
	std::string line;
	
	if(argc == 1){
		std::cout<< "There is one output" << std::endl;
	}
	
	else if(argc ==2 ){
		std::cout<< "There is two outputs and hopefully and input file" << std::endl;
	}
	
	std::ifstream input_file (argv[1]);
	std::ofstream  output_file;
	
	
	//input_file.close();
	
	output_file.open ("output.txt");
	
	output_file << "HI";
	
	char c;
	
	while(input_file.good()){
		
		c = input_file.get();
		
		if(c == '\n' || c == '\0'){
			++number_of_lines;
		}	
	}
	
	std::cout<< "num lines is: " << number_of_lines << std::endl;
	
	input_file.close();
	
	input_file.open(argv[1]);
	
	bool space_only;
	int total_word_count = 0;
	
	while(input_file.good()){
		input_file>>std::ws;
		std::getline(input_file, line);
		std::cout<<line<<std::endl;
		total_word_count = read_string(line) + total_word_count;
		
	}
	
	std::cout << "Total Word Count: " << total_word_count << std::endl;
	
	input_file.close();
	

	
	
	
	
	return 0;
}