#ifndef INT_CMD_H_
#define INT_CMD_H_

	#include "./cmd_type.h"
	#include "./process_cmd.h"
	#include <errno.h>
	#include <readline/readline.h>
	#include <readline/history.h>
	#include <unistd.h>

	void exec_internal(cmd_type * cmd, int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx, int array_size);	

	void executeHistory(int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx, int array_size);

	void executeDirectory(cmd_type * cmd, char ** cmd_array, int array_size);
	//void exec_internal(cmd_type * cmd, int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx);	
		

#endif //INT_CMD_H_
