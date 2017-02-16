#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

struct UnionFind{
	int p[1000];
	int rank[1000];
	int set_size[1000]; 
	int disjoint_sets;
	
	void union_find_setup(int N){

		for(int i = 0; i<=N; ++i){
			rank[i] = 0;
			p[i] = 0;
		}
		for(int i = 0; i<=N; ++i){
			set_size[i] = 1;	
		}
		
		for(int i = 0; i<=N; ++i){
			p[i] = i;
		}
		disjoint_sets = N;
	}
	
	int find_set(int i){
		return (p[i] == i) ? i: (p[i] = find_set(p[i]));
	}
	bool is_same_set(int i, int j){
		return find_set(i) == find_set(j);
	} 
	void union_set(int i, int j){
		if(!is_same_set(i,j)){
			int x = find_set(i), y = find_set(j);
			--disjoint_sets;
			if(rank[x] > rank[y])  {p[y] = x;  set_size[find_set(x)] += set_size[find_set(y)];}
			else{
				p[x] = y; set_size[find_set(y)] += set_size[find_set(x)];
				if(rank[x] == rank[y]) ++rank[y]; 
			}
			
		}
	}
	int num_disjoint_sets(){
		return disjoint_sets;
	}
	int size_of_set(int i){
		return set_size[find_set(i)];
	}
};
		


int main(){
	//vi yess(1000), noos(1000);
	
	string input_line;
	string c = "c";
	
	int passes;
	scanf("%d", &passes);
	int *yess = (int*) malloc(sizeof(int) * passes);
	int *noos = (int*) malloc(sizeof(int) * passes);
	//getline(cin, input_line);
	//passes = stoi(input_line);
	
	for (int z = 0; z<passes; ++z){
		int num_nodes;
		scanf("\n%d\n", &num_nodes);
		
		int i, j;
		string cmd;
		
		UnionFind *union_find = (UnionFind*)malloc(sizeof(UnionFind)*num_nodes); 
		union_find->union_find_setup(num_nodes);
		
		string i_str, j_str;
		getline(cin, input_line);
		while(!input_line.empty()){
			
			istringstream ss (input_line);
			ss>>cmd;
			ss>>i;
			ss>>j;
			
			if(cmd.compare("c") == 0){
				union_find->union_set(i,j);
			}
			else{
				if(union_find->is_same_set(i,j)){
					++yess[z];
				}
				else{
					++noos[z];
				}
			}
			
		
		getline(cin, input_line);
		}
		free(union_find);
	}
	for(int z = 0 ; z<passes; ++z){
		cout << yess[z] << "," << noos[z]; 
		if (z == passes-1){
			cout << endl;
		}
			
		else {
			cout << endl << endl;
		}
	}
	return 0;
}
