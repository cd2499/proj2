#ifndef CMD_TYPE_H_
#define CMD_TYPE_H_

typedef enum {dir_cd_cmd,
	      dir_exit_cmd,
	      dir_pwd_cmd,
	      envvar_cmd,
	      hist_cmd,
	      pipe_cmd,
 	      redirect_cmd} cmd_type; 



#endif //CMD_TYPE_H_
