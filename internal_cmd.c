	#include "./cmd_type.h"

	void exec_internal(cmd_type * cmd, int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx);	
	void executeHistory(int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx){
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
			parseCommand(cmd_array[0], a, "-", NULL, NULL, NULL);
			cmd_array_new[0] =  the_list[hist_cnt - (atoi(a[1])+1)]->line;
			
			array_size = parseCommand(cmd_array_new[0], cmd_array, " ", pipe_cnt, redirect_cnt, redirect_idx);

			printf("about to call routeCommand\n");
			is_internal = routeCommand(cmd_array, array_size, hist_cnt, pipe_cnt, redirect_cnt, redirect_idx, cmd);
			
			if (is_internal)
				exec_internal(cmd, hist_cnt, cmd_array, pipe_cnt, redirect_cnt, redirect_idx);
			else
				printf("looks like its external\n");	
//			commandDirectory(the_list[hist_cnt - atoi(a[1])]->line, hist_cnt);	
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



	void exec_internal(cmd_type * cmd, int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx){	
		
		if (*cmd == hist_cmd)
			executeHistory(hist_cnt, cmd_array, pipe_cnt, redirect_cnt, redirect_idx);}


