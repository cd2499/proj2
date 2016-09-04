	#include <stdio.h>
	#include <unistd.h>
	#include "./cmd_type.h"	

	void getShellPrompt(char * shellprompt, int hist_cnt){
		char *user;
		char machine[64];
	 
		if( (user = getenv("USER")) == NULL)
			write(STDERR_FILENO,"Error: failed to get user name.",32);
		if( (gethostname(machine,256)) ==-1)
			write(STDERR_FILENO,"Error: failed to get host name.",32);

		sprintf(shellprompt, "< %d %s@%s:>", hist_cnt, user, machine);}


	int parseCommand(char * usercmd_, char ** cmd_array, char * delim, int * pipe_cnt, int * redirect_cnt, int * redirect_idx){
		int array_size = 0;	
		char usercmd[1000];
		char * parsecmd = ""; 
		
		sprintf(usercmd, "%s", usercmd_);
		parsecmd = strtok(usercmd, delim);
	

		while(parsecmd != NULL)	{
			cmd_array[array_size++] = parsecmd;
		//	printf("arraysize %d and val %s\n", array_size, parsecmd);
			if ( (strcmp(parsecmd,">") == 0) ||  (strcmp(parsecmd, "<") == 0) ){	
				redirect_idx[(*redirect_cnt)] = array_size-1;	
				(*redirect_cnt)++;}
			else if ( (strcmp(parsecmd, "|") == 0) )
				(*pipe_cnt)++;
			
	
			parsecmd = strtok(NULL, delim);}

		return array_size;}


	
	int routeCommand(char ** cmd_array, int array_size, int hist_cnt, int * pipe_cnt, int * redirect_cnt, int * redirect_idx, cmd_type * cmd){
	
	//started commenting out here	
		//printf("new pipe count is %d and new redirect count is %d\n", *pipe_cnt, *redirect_cnt);
		//printf("cmd---------->%d\n",*cmd);
		printf("in route cmd_array[0] passed is %s\n", cmd_array[0]);
		if ( ((cmd_array[0][0]) == '!') || (strcmp(cmd_array[0], "hist") == 0) ){	
			*cmd = hist_cmd;
			return 1;}
		
		else if ( (strcmp(cmd_array[0], "pwd") == 0) ){
			*cmd = dir_cmd;
			return 1;}
			//executeInternal(usercmd, cmd_array, array_size, 0); 	//	printf("%s\n",&(*cmd_array[0][0]))                                          				
		else if ( (strcmp(cmd_array[0], "cd") == 0) ){
			*cmd = dir_cmd;
			return 1;}
			//executeInternal(usercmd, cmd_array, array_size, 1);
//		if (redirect_cnt > 0)	
//			executeIORedirect(usercmd, cmd_array, array_size, redirect_cnt_val, redirect_idx);
//	
//		else if (pipe_cnt_val > 0)
//			executePipeline(usercmd, cmd_array, array_size);			
//		//task2
//		 if ( ( (usercmd[0]) == '!') || (strcmp(cmd_array[0], "hist") == 0) )
//			printf("hello\n"); //executeHistory(hist_cnt, usercmd, cmd_array);

//	
//		else if ( (strcmp(cmd_array[0], "pwd") == 0) )
//			executeInternal(usercmd, cmd_array, array_size, 0);
//		
//		else if ( (strcmp(cmd_array[0], "cd") == 0) )
//			executeInternal(usercmd, cmd_array, array_size, 1);
//	
//		else if (array_size == 1)
//			executeExternal(usercmd, cmd_array, 0);
//	
//		else if ( (usercmd[0] == '.') || (usercmd[1] == '/') || (usercmd[0] == '/') )
//			executeExternal(usercmd, cmd_array, 1);		
//	
//		else if ( (strcmp(cmd_array[0], "set")) == 0)
//			executeInternal(usercmd, cmd_array, array_size, 2);
//	
//		else if ( (strcmp(cmd_array[0], "delete")) == 0)	
//			executeInternal(usercmd, cmd_array, array_size, 3);
//	
//		else if ( (strcmp(cmd_array[0], "print")) == 0)
//			executeInternal(usercmd, cmd_array, array_size, 4);
//		else
//		{
//			printf("you're in the default catch all execv\n");
//			executeExternal(usercmd, cmd_array,0);
//		}
		return 0;	
		memset(cmd_array, 0, sizeof (*cmd_array));
		}
