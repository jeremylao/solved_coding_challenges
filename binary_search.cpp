#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>


struct node {
	int key_value;
	node *left;
	node *right;
};


class binary_tree{
	
	public:
		binary_tree();
		~binary_tree();
		
		void insert(int key);
		node *search(int key);
		void destroy_tree();
		
	private:
	
		void destroy_tree(node *leaf);
		void insert(int key, node *leaf);
		node *search(int key, node *leaf);
		
		node *root;
};
