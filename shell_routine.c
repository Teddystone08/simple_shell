#include "main.h"


/**
 * cpy_path - copies the argument passed
 *
 * @path: string argument
 * @line: integer
 * @cmd_name: string
 * @shell_name: string
 * Return: copied path (success), NULL (fail)
 */
char *cpy_path(char *shell_name, char *cmd_name, int line, char *path)
{
	int i = 0, j = 0;
	char *new_path = NULL;

	i = _strlen(path) + 1;
	new_path = (char *)calloc(i, sizeof(char));
	if (new_path == NULL)
	{
		error_print(shell_name, cmd_name, line, MALLOC_ERROR);
	}
	while (j < i)
	{
		new_path[j] = path[j];
		j++;
	}
	return (new_path);
}


/**
 * run_cd - checks if command is cd and executes it
 *
 * @cmd: command passed
 * @path: command passed
 * @old: previous directory
 * @shell_name: string
 * @line: integer
 * @env: environment
 * Return: 0 (success), 1 (fail)
 */
int run_cd(char *shell_name, int line,
		char *cmd, char **path, char **old, char **env)
{
	char *str = *path;
	char *ptr = NULL;

	if (_strcmp(cmd, "cd") == 0)
	{
		check_prev_cmd(str, path, *old, env);
		ptr = *path;
		chg_dir(shell_name, cmd, line, ptr);
		printf("str: %s\n", str);
		printf("ptr: %s\n", ptr);
		free(str);
		return (0);
	}
	return (1);
}



/**
 * shell_routine - runs a loop that calls shell functions
 * @shell_name: string
 * @env: environment
 *
 * Return: Nothing.
 */
void shell_routine(char *shell_name, char **env)
{
	char **args, *path_line = NULL, *new, *old = NULL, *path, str[] = "exit";
	char old_str[] = "OLDPWD", new_str[] = "PWD", path_str[] = "PATH";
	int i = 1, len, cd_status, line = 1;
	size_t n = 4;

	old = getenv_val(old_str, env), new = getenv_val(new_str, env);
	path_line = getenv_val(path_str, env);
	do {
		len = 0, cd_status = 1;
		args = getline_args(old, new, path_line);
		if (args != NULL)
		{
			while (args[len] != NULL)
			{
				len++;
			}
		}
		else if (args == NULL)
		{
			continue;
		}
		if (len == 1 && _strncmp(args[0], str, n) == 0)
		{
			free(old), free(new), free(path_line), free_args(args);
			exit_call(shell_name, line, MALLOC_ERROR, 88);
		}
		if (len == 2)
		{
			path = cpy_path(shell_name, args[0], line, args[1]);
			cd_status = run_cd(shell_name, line, args[0], &path, &old, env);
		}
		if (cd_status == 1)
		{
			seek_cmd(shell_name, line, args, env, path_line);
		}
		update_pwd(shell_name, args[0], line, cd_status, &old, &new);
		free_args(args);
	} while (i);
}

