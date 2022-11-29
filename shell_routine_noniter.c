#include "main.h"


/**
 * shell_routine_noniter - runs a loop that calls shell functionsi
 * @shell_name: string
 * @env: environment
 *
 * Return: Nothing.
 */
void shell_routine_noniter(char *shell_name, char **env)
{
	char **args, *new, *old = NULL, *path, str[] = "exit", path_str[] = "PATH";
	char old_str[] = "OLDPWD", new_str[] = "PWD", *path_line = NULL;
	int i = 1, len, cd_status, line = 1;
	size_t n = 4;

	old = getenv_val(old_str, env), new = getenv_val(new_str, env);
	path_line = getenv_val(path_str, env);
	do {
		len = 0, cd_status = 1;
		args = getline_args_noniter(old, new, path_line);
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

