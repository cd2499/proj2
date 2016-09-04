#ifndef PRCSS_CMD_H_
#define PRCSS_CMD_H_
	
	#include <stdio.h>
	#include <unistd.h>
	#include "./cmd_type.h"	
	#include "./internal_cmd.c"

	void getShellPrompt(char * shellprompt, int hist_cnt);

	int parseCommand(char * usercmd_, char ** cmd_array, char * delim, int * pipe_cnt, int * redirect_cnt, int * redirect_idx);
	
	int routeCommand(char ** cmd_array, int array_size, int hist_cnt, int * pipe_cnt, int * redirect_cnt, int * redirect_idx, cmd_type * cmd);

	void processCommand(cmd_type * cmd, int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx, int is_internal);

#endif //PRCSS_CMD_H__
