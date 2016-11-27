#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>

struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

struct node* new_node(int data) { 
  struct node* node = new(struct node);    // "new" is like "malloc" 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL;

  return(node); 
} ;


/* 
 Given a binary tree, return true if a node 
 with the target data is found in the tree. Recurs 
 down the tree, chooses the left or right 
 branch by comparing the target to each node. 
*/ 
static int lookup(struct node* node, int target) { 
  // 1. Base case == empty tree 
  // in that case, the target is not found so return false 
  if (node == NULL) { 
    return(false); 
  } 
  else { 
    // 2. see if found here 
    if (target == node->data) return(true); 
    else { 
      // 3. otherwise recur down the correct subtree 
      if (target < node->data) return(lookup(node->left, target)); 
      else return(lookup(node->right, target)); 
    } 
  } 
} 


struct node* insert(struct node* node, int data) { 
  // 1. If the tree is empty, return a new, single node 
  if (node == NULL) { 
    return(new_node(data)); 
  } 
  else { 
    // 2. Otherwise, recur down the tree 
    if (data <= node->data) node->left = insert(node->left, data); 
    else node->right = insert(node->right, data);

    return(node); // return the (unchanged) node pointer 
  } 
} ;


struct node* build123a(){
	struct node* root = new_node(2);
	struct node* lchild = new_node(1);
	struct node* rchild = new_node(3);
	
	root->left = lchild;
	root->right = rchild;
	
	return root;
}





int main(){
	
	node::node *root;
	
	//root = malloc(sizeof(node::node));
	
	root = build123a();
	
	
	std::cout<< "center: " << root->data << std::endl;
	std::cout<< "right: " << root->right->data << std::endl;
	std::cout<< "left: " << root->left->data << std::endl;
	
	
	return 0;
}