#ifndef INT_CMD_H_
#define INT_CMD_H_

	#include "./cmd_type.h"


	void exec_internal(cmd_type * cmd, int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx);	

	void executeHistory(int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx);

	void exec_internal(cmd_type * cmd, int hist_cnt, char ** cmd_array, int * pipe_cnt, int * redirect_cnt, int * redirect_idx);	
		

#endif //INT_CMD_H_
