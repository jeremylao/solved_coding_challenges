#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "macros.h"
#include "process.h"
#include "control.h"

Process* original_process[MAXPROCESSES];
Process* process_array[MAXPROCESSES];
Process* ready_process;

int random_file_index = 0;
int time_count = 0;

int random_os(int state, int u){
	int rdm_local = 0;
	
	if(random_file_index == (RANDOM_NUM)){
		random_file_index=0;
	}
		rdm_local = random_numbers[random_file_index];
		if(verbose == 1){
			if(state == RUNNING){
				printf("Find burst when choosing ready process to run %d \n", rdm_local);
			}
			else if(state == BLOCKED){
				printf("Find I/O burst when choosing ready process to run %d \n", rdm_local);
			}
		}
		random_file_index = ++random_file_index;
		return (1 + (rdm_local % u));
}

//read a process from a file, create a node, store it in the node, and push it onto the queue
void read_process(int *process_index, FILE *input_file){
	int i, temp_at, temp_tc, temp_cb, temp_io, temp_count;
	i = temp_count = 0;
	char *temp_char;
	
	while(!feof(input_file)){
		fscanf(input_file, "%d ", &temp_count);
		
		if(temp_count > MAXPROCESSES){
			printf("CPU overloaded, INPUT COUNT %d > MAXPROCESSES %d \n", temp_count, MAXPROCESSES);
		}
		
		for(i=0; i<temp_count; ++i){
			Process *temp;
			temp = (Process*) malloc(sizeof(Process));
			fscanf(input_file, " %*c%d %d %d %d%*c ", &temp_at, &temp_cb, &temp_tc,  &temp_io);
			
			//store the values into the 'temp' Process node
			temp->in_id = i;
			temp->A = temp_at;
			temp->B = temp_cb;
			temp->remaining_C = temp_tc;
			temp->C = temp_tc;
			temp->IO = temp_io;
			temp->state = NOT_STARTED;
			temp->index = (1000 * temp_at) + i;
			temp->lcfs_order=0;
			temp->finish_time = 0; 
			temp->turnaround_time = 0; 
			temp->io_time = 0; 
			temp->wait_time= 0;    		//processes vitals
			temp->quantum = 2;
			temp->run_time = 0;

			
			original_process[i] = temp;
			process_array[i] = temp;
			//printf("\n this is at %d, tc %d, cb %d, io %d \n", temp_at, temp_tc, temp_cb, temp_io);  //seeing what was read from the file instantly
		}
		fscanf(input_file, "%*[^\n]");

		//printf("in while"); accounting
	}
	
	//printf("\n this is at %d, tc %d, cb %d, io %d \n", temp_at, temp_tc, temp_cb, temp_io); //want to see if the 
	*process_index = temp_count;
	
	//re-size the ready_queue once know how many processes there are in total, it will never be bigger than what have
	ready_process = (Process*) realloc(ready_process,temp_count * sizeof(Process));
	
}

void sort_input_array(int n){

	int i, j, min_index;
	Process *temp_sort; 
	temp_sort = (Process*) malloc(sizeof(Process));
	 
	if(n==0){
		printf("nothing to sort\n");
		return;
	}
	
	else if(n == 1){
		return;
	}
	
	else{
		for(i=0; i<(n-1); ++i){
			min_index = i;
			for(j = (i+1); j < n; ++j){
				if (process_array[j]->index < process_array[min_index]->index){
					min_index = j;
				}
				if(min_index != i){
					temp_sort = process_array[i];
					process_array[i] = process_array[min_index];
					process_array[min_index] = temp_sort;
				}
			}
		}
		for(i=0; i<n; ++i){
			process_array[i]->pid = i;
		}
	}
	
	return;
}