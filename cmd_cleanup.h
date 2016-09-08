#ifndef CMD_CLEANUP_H_ 
#define CMD_CLEANUP_H_

void cmd_cleanup(char * user_cmd, int * pipe_cnt, int * redirect_cnt, int * redirect_idx);


void cmd_cleanup(char * user_cmd, int * pipe_cnt, int * redirect_cnt, int * redirect_idx){
	free(user_cmd);
	*pipe_cnt = 0;
	*redirect_cnt = 0;
	*redirect_idx = 0;}

#endif //CMD_CLEANUP_H_ 
