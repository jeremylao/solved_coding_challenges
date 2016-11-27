#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>


struct Entry{
	std::string first_name;
	std::string last_name;
	int age;
};

//create a class that is an Entry, handles adding and deleting names from the book, and sorting by the last name


int main(int argc, char *argv[]){
	
	struct Entry* entry_one = new Entry;
	struct Entry by_value; 
	
	std::vector<Entry*> book;
	
	int user_input = 0;
	std::string temp_first_name;
	
	while (true) {
		
		std::cout << "Add an entry: 1, Stop Running: 5"  << std::endl;
		std::cin >> user_input;
		
		if(user_input == 5){
			break;
		}
		
		struct Entry* entry_one = new Entry;
		std::cout<< "Entery first name" << std::endl;
		std::cin >> entry_one->first_name;
		std::cout<< "Enter last name" << std::endl;
		std::cin>> entry_one->last_name;
		book.push_back(entry_one);
		
	}
	
	//entry_one = (struct entry*) malloc(sizeof(struct entry));
	
	std::string pointer = "john";
	entry_one->first_name = pointer;
	entry_one->last_name = "smith";
	entry_one->age = 76;
	
	book.push_back(entry_one);
	
	by_value.first_name = "connor";
	by_value.last_name = "smith";
	
	
	std::cout<< "Entry One Name: " << entry_one->first_name << std::endl;
	std::cout<< "Entry One Last Name: " << entry_one->last_name << std::endl;
	std::cout<< "Entry One Age: "  << entry_one->age << std::endl;
	
	std::cout << "Entry Two Name: " << by_value.first_name << std::endl;
	
	
	std::cout << "Vector front: "  << book.front()->first_name  <<std::endl;
	std::cout << "Vector back:" << book.back()->first_name << std::endl;
	std::cout << "Vector size: " << book.size() << std::endl;
	std::cout << "Name at 2 :"  << book.at(1)->first_name << std::endl;
	
	for(int i = 0 ; i<book.)
	
	return 0;
}