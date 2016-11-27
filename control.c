#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "macros.h"
#include "process.h"
#include "control.h"

int random_numbers[RANDOM_NUM+1];
int verbose=0;

//parse_command : input is ./program -s[F|S|R[0-9]+]
void parse_command_line(FILE *input_file, FILE *random_file, int *sched_flag_local, int *quantum_local, int *process_num_local, int argc, char *argv[]){
	
	int temp_int = 0;
	int i = 1;
	int first_file = 1;
	
	random_file = fopen("random-numbers", "r");
	store_random_num(random_file);
				
	for (i; i < argc; ++i) {
		if (strcmp(argv[i], "-verbose") == 0) {
            verbose = 1;
		}
		else if(argv[i][0] == '-'){
			if(argv[i][1] == 'F'){
				*sched_flag_local = FCFS;	
				temp_int = 0xFFFF;
			}
			else if(argv[i][1] == 'L'){
				*sched_flag_local = LCFS;
				temp_int = 0xFFFF;
			}
			else if(argv[i][1] == 'R'){
				*sched_flag_local = RRQ2;
				temp_int = 2;
				//sscanf(argv[i]+3, "%d", &temp_int);
			}
			else if(argv[i][1] == 'H'){
				*sched_flag_local = HPRN;
				temp_int = 0xFFFF;
			}
		}
		else{
			if(first_file){
				input_file = fopen(argv[i], "r");
				read_process(process_num_local, input_file);
				first_file = 0;
			}
		}
	}
	*quantum_local = temp_int;
}

void store_random_num(FILE *random_num_file){
	int i = 0;
	while(!feof(random_num_file)){
		fscanf(random_num_file,"%d",&random_numbers[i]);
		++i;
	}
}