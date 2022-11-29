#include "main.h"


/**
 * _getenv - returns a pointer to the variable name
 * @name: name of variable to search for
 * @env: environment
 *
 * Description: program searches through environment strings
 * Return: pointer to string (success), NULL (fail)
 */
char *_getenv(char *name, char **env)
{
	char *ptr = NULL, *str = NULL;

	if (_strlen(name) < 1 || name == NULL)
	{
		return (ptr);
	}

	ptr = getenv_line(name, env);
	if (ptr != NULL)
	{
		str = _strdup(ptr);
	}
	return (str);
}


/**
 * get_paths - returns a pointer to paths in environment variable
 * @shell_name: string
 * @cmd_name: command
 * @line: integer
 * @ptr: string
 * Return: pointer to string (success), NULL (fail)
 */
char **get_paths(UNUSED char *shell_name,
		UNUSED char *cmd_name, UNUSED int line, char *ptr)
{
	char delim[] = ":\n";
	char **paths = NULL;

	paths = get_substrings(ptr, delim);
	return (paths);
}



/**
 * seek_cmd - execute commands after appending path where needed
 * @shell_name: shell invocation command
 * @line: integer
 * @args: pointer to arguments
 * @env: environment
 * @path_line: path environment variable
 * Return: integer
 */
int seek_cmd(char *shell_name, int line, char **args,
		char **env, char *path_line)
{
	int status = 0, i = 0;
	char *cmd = NULL, *path = NULL, **paths = NULL, *old_cmd = NULL;
	char delim[] = " :\n";

	old_cmd = args[0];
	if (old_cmd == NULL || _strlen(old_cmd) < 1)
	{
		return (-1);
	}
	status = access(args[0], X_OK);
	if (status == -1)
	{
		paths = get_substrings(path_line, delim);
		if (paths == NULL)
		{
			error_print(shell_name, args[0], line, MALLOC_ERROR);
			return (-1);
		}
		for (i = 0; paths[i] != NULL; i++)
		{
			path = path_seek(shell_name, line, paths[i], args[0]);
			if (path != NULL)
			{
				break;
			}
		}
		if (path != NULL)
		{
			cmd = append_path(shell_name, line, path, args[0]);
			args[0] = cmd;
		}
		free_args(paths);
	}
	shell_execute(shell_name, line, args, env);
	args[0] = old_cmd;
	free_one(cmd);
	return (0);
}

