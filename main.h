#ifndef MAIN_H
#define MAIN_H

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>


		/* MACROS DEFINITION */
/*************************************************************/
#define LINE_BUFF 50
#define SHELL_DELIM " :\n\t\r\a"
#define UNUSED __attribute__((unused))
#define PATH_SIZE 30

/* ERROR MESSAGES TO DISPLAY */
#define EXECVE_ERROR "failed"
#define EXECVE_CHILD_ERROR "process limit reached"
#define COMMAND_EXIST_ERROR "not found"
#define MALLOC_ERROR "out of memory"
#define DIR_PERMISSION_ERROR "directory permission denied"
#define DIR_EXIST_ERROR "directory does not exist"
#define CHG_DIR_PATH_ERROR "inavlid directory path"
#define CHG_DIR_NAME_ERROR "path name exceeds limit"
#define CHG_DIR_LOOP_ERROR "path contains symbolic link loop"
#define SET_ENV_ERROR "environment set error"
#define GET_CWD_ERROR "environment get working directory error"
#define PATH_ERROR "cannot open path"


		/* FUNCTION DEFINITIONS */
/**************************************************************/
char *_strdup(char *string);
int _strncmp(char *str1, char *str2, unsigned int n);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strtok(char *string, char *substring);
size_t _strspn(const char *s, const char *accept);
char **get_substrings(char *string, char *delim);
char *getenv_line(char *string, char **env);
char *_getenv(char *name, char **env);
char **get_paths(char *shell_name, char *cmd_name, int line,
		char *path_line);
int seek_cmd(char *shell_name, int line, char **args,
		char **env, char *path_line);
char *path_seek(char *shell_name, int line, char *path, char *cmd);
char *append_path(char *shell_name, int line, char *path, char *cmd);
char **getline_args(char *old, char *curr, char *path_line);
char **getline_args_noniter(char *old, char *curr, char *path_line);
void shell_routine(char *shell_name, char **env);
void shell_routine_noniter(char *shell_name, char **env);
int run_cd(char *shell_name, int line, char *cmd, char **path,
		char **old, char **env);
char *cpy_path(char *shell_name, char *cmd_name, int line, char *path);
void free_args(char **args);
void free_one(char *str);
int shell_execute(char *shell_name, int line, char **args, char **env);
void error_print(char *shell_name, char *cmd_name, int line, char *str);
void exit_call(char *shell_name, int line, char *str, int call);
void exit_feof(char *old, char *curr, char *lineptr, char *path_line, int flag);
char *getenv_val(char *string, char **env);
int chg_dir(char *shell_name, char *cmd_name, int line, char *ptr);
void check_prev_cmd(char *curr, char **n, char *old, char **env);
void update_pwd(char *shell_name, char *cmd_name, int line,
		int cd_status, char **old, char **curr);

#endif /* MAIN_H */

