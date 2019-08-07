#ifndef _TOOL_H_
#define _TOOL_H_

//执行shell命令，带输出
int exec_cmd(const char *cmd, char **out, int *out_len);
//查看CPU核数
int get_cpu_cores();

#endif //_TOOL_H_
