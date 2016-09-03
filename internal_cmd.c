	#include "./cmd_type.h"

	
	void executeHistory(int hist_cnt, char ** cmd_array){
		register HIST_ENTRY ** the_list = history_list();		
		//cmd_type cmd_val = hist_cmd;
		cmd_type cmd_val = envvar_cmd;
		cmd_type * cmd = &cmd_val;
		//char ** cmd_array =  the_list[hist_cnt - atoi(a[1])]->line;
		
	printf(" val is %d\n", *cmd);			
			
		if (cmd_array[0][1] == '-')
		{				
			printf("here!!\n");
			char * a[400];
			printf("here!\n");
			//char * cmd_array_[200];			
			printf("hre %s\n", cmd_array[0]);
			parseCommand(cmd_array[0], a, "-", NULL, NULL, NULL);
			printf("ok \n");
			printf("ths %s\n", the_list[hist_cnt - atoi(a[1])]->line);
			//cmd_array[0] =  the_list[hist_cnt - atoi(a[1])]->line;
			printf("Make\n");		
			printf("hre---->%s\n", cmd_array[0]);
			routeCommand(cmd_array, 0, hist_cnt, 0, 0, 0, cmd);
	//char ** cmd_array, int array_size, int hist_cnt, int * pipe_cnt, int * redirect_cnt, int * redirect_idx, cmd_type * cmd)		
	
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
		printf("did i make it this far\n");	
	//	free(cmd);  DOESNT LIKE THIS
}



	void exec_internal(cmd_type * cmd, int hist_cnt, char ** cmd_array){
		
		if (*cmd == hist_cmd)
			executeHistory(hist_cnt, cmd_array);}


