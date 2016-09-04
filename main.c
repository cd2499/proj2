	/* Developer: Greg Olkowski (cd2499) - 
	-  Date: 2016-08-21 		     -
	-  Project: shell 		    */

	#include <stdbool.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <readline/readline.h>
	#include <readline/history.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include "./cmd_type.h"
	#include "./process_cmd.h"
	#include "./internal_cmd.h"
	
	
	int main(){
		
		int array_size;  
		int hist_cnt = 1;
		int is_internal = 0;
		int pipe_cnt_val = 0;
		int redirect_cnt_val = 0;
		char shellprompt[256];
		int * pipe_cnt = &pipe_cnt_val;
		int * redirect_cnt = &redirect_cnt_val;
		int * redirect_idx = (int[2]){0,0};
		char * cmd_array[400]; 
		char * user_cmd;
		cmd_type cmd_val = hist_cmd;
		cmd_type * cmd = &cmd_val; 


		using_history();
        
		printf("hit ctr + d to exit prompt\n");
         
         	
        	getShellPrompt(shellprompt, hist_cnt);	
         
        	while ((user_cmd = readline(shellprompt))) {
         		add_history(user_cmd);  
		     	array_size = parseCommand(user_cmd, cmd_array, " ", pipe_cnt, redirect_cnt, redirect_idx);
         		is_internal = routeCommand(cmd_array, array_size, hist_cnt, pipe_cnt, redirect_cnt, redirect_idx, cmd);
       			parseCommand(cmd, hist_cnt, cmd_array, pipe_cnt, redirect_cnt, redirect_idx, is_internal); 
			processCommand(cmd, hist_cnt, cmd_array, pipe_cnt, redirect_cnt, redirect_idx, is_internal); 
         		
			printf("cmd----->%d\n", *cmd);
			free(user_cmd);		
        		
			*pipe_cnt = 0;
			*redirect_cnt = 0;
			*redirect_idx = 0; 
         		
			getShellPrompt(shellprompt,++hist_cnt);}

		return 0;}
	
