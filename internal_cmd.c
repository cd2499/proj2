	#include "./cmd_type.h"
	#include "./internal_cmd.h"
	#include "./process_cmd.h"

	void executeHistory(int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx, int array_size){
		register HIST_ENTRY ** the_list = history_list();		
		cmd_type cmd_val = hist_cmd;
		cmd_type * cmd = &cmd_val;
		char * cmd_array_new[400];

		*pipe_cnt = 0;
		*redirect_cnt = 0;
		*redirect_idx = 0;
			
			
		if (cmd_array[0][1] == '-')
		{				
			char * a[400];
			int array_size;
			int is_internal = 0;
			parseCommand(cmd_array[0], a, "-", NULL, NULL, NULL); //gmo make sure adding null doesnt cause an issue
			cmd_array_new[0] =  the_list[hist_cnt - (atoi(a[1])+1)]->line;
			
			array_size = parseCommand(cmd_array_new[0], cmd_array, " ", pipe_cnt, redirect_cnt, redirect_idx);

			is_internal = routeCommand(cmd_array, array_size, hist_cnt, pipe_cnt, redirect_cnt, redirect_idx, cmd);
				
			processCommand(cmd, hist_cnt, cmd_array, pipe_cnt, redirect_cnt, redirect_idx, is_internal, array_size); 
		}
	//	else if(strcmp(cmd_array[0], "hist") == 0)
//		{	
//			register int i;

//			printf("%s\n", cmd_array[0]);
//			if (the_list)
//				for (i = 0; (the_list[i] && i<atoi(cmd_array[1])) ; i++)
//					printf ("%d: %s\n", i + history_base, the_list[i]->line);
//		}
//		else 
//		{	
//			char * a[400]; 
//			parseCommand(usercmd, a, "!", NULL, NULL, NULL);
//			commandDirectory(the_list[atoi(a[0])-1]->line, hist_cnt);	
//		}
	//	free(cmd);  DOESNT LIKE THIS
}


	void executeDirectory(cmd_type * cmd, char ** cmd_array, int array_size ){
		if (*cmd == dir_pwd_cmd){
			if(array_size != 1)
				write(STDERR_FILENO, "Error: Expecting only one argument for printing working directory\n", 128);
			else{
				char * cwd = malloc(400);
				
				if ( (getcwd(cwd, 400)) == NULL)
					write(STDERR_FILENO, "Error: failed to get current working directory\n", 128);
				else
					printf("%s\n", cwd);}}
	
		else if (*cmd == dir_cd_cmd){
			if(array_size != 2)
				write(STDERR_FILENO, "Error: Expecting two arguments for changing directory\n", 128);
			else{
				if ( (chdir(cmd_array[1])) != 0)
					write(STDERR_FILENO, "Error: failed to change directory\n", 128);}}
		
		else if (*cmd == dir_exit_cmd)
				exit(0);}



	void exec_internal(cmd_type * cmd, int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx, int array_size){	
		
		if (*cmd == hist_cmd)
			executeHistory(hist_cnt, cmd_array, pipe_cnt, redirect_cnt, redirect_idx, array_size);
		else if ((*cmd == dir_pwd_cmd) || (*cmd == dir_cd_cmd))
			executeDirectory(cmd, cmd_array, array_size);}


