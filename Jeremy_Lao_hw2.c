#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


#include "macros.h"
#include "process.h"
#include "control.h"
#include "output.h"
#include "des_1.h"


int main (int argc, char *argv[]) {
	
	FILE *input_file;
	FILE *random_file;
	
	int tot_process, sched_flag, quantum, i, rdm_num;
	tot_process = sched_flag = i = 0;
	quantum = 2;
	
	if(argc == 1){
		printf("you didn't enter any options\n");
		exit(1);
	}
	
	for( i = 0; i<4; ++i){
		
		switch(i){
			
			case(0):
				random_file_index = 0;
				global_io = 0;
				time_count = 0;
				sched_flag = FCFS;
			break;
			
			case(1):
				random_file_index = 0;
				global_io = 0;
				time_count = 0;
				sched_flag = LCFS;
			break;
			
			case(2):
				random_file_index = 0;
				global_io = 0;
				time_count = 0;
				sched_flag = RRQ2;
			break;
			
			case(3):
				random_file_index = 0;
				global_io = 0;
				time_count = 0;
				sched_flag = HPRN;
			break;
			
			default:
			break;
		}
	
	//random numbers are stored in the parse_command_line methods
	parse_command_line(input_file, random_file, &sched_flag, &quantum, &tot_process, argc, argv);
	
	sort_input_array(tot_process);
	
	print_header(tot_process);
	
	int DES_TIME_CLOCK=0;
	int next_process_state;
	int current_process_index=0;
	int next_process_index=0;
	int change_event = FALSE;
	int io_b, cpu_b, burst;
	
	
		
		
	while(counter(tot_process)){
		
		before_cycle_stmt( DES_TIME_CLOCK, tot_process, sched_flag);
		
		do_blocked(  DES_TIME_CLOCK,  tot_process);

		do_running( DES_TIME_CLOCK, tot_process, sched_flag);

		do_arriving(  DES_TIME_CLOCK,  tot_process);

		do_ready(  DES_TIME_CLOCK,  tot_process, sched_flag);

		++DES_TIME_CLOCK;
	}
	
	scheduler_text(sched_flag);
	
	end_des_summary(DES_TIME_CLOCK, tot_process);
	
	}
	
	return 0;
}
