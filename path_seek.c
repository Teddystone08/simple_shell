#include "main.h"


/**
 * append_path - preppends path to a command
 * @path: path to command
 * @cmd: command
 * @shell_name: string
 * @line: integer
 *
 * Return: pointer to new string
 */
char *append_path(char *shell_name, int line, char *path, char *cmd)
{
	int len, j;
	char *new_cmd = NULL;

	len = _strlen(cmd);
	len += _strlen(path) + 2;
	new_cmd = (char *)calloc(len, sizeof(char));
	if (new_cmd == NULL)
	{
		error_print(shell_name, cmd, line, MALLOC_ERROR);
		return (new_cmd);
	}
	for (j = 0; path[j] != '\0'; j++)
	{
		new_cmd[j] = path[j];
	}
	new_cmd[j] = '/', j++;
	for (len = 0; cmd[len] != '\0'; len++, j++)
	{
		new_cmd[j] = cmd[len];
	}
	new_cmd[j] = '\0';
	return (new_cmd);
}

/**
 * path_seek - searches for file in path
 * @path: directory to search
 * @cmd: executable name
 * @line: integer
 * @shell_name: string
 *
 * Return: path to file (success), NULL (fail)
 */
char *path_seek(UNUSED char *shell_name, UNUSED int line,
		char *path, char *cmd)
{
	char *str = NULL;
	DIR *dp;
	struct dirent *dirp;

	if (path == NULL || cmd == NULL)
	{
		return (str);
	}

	dp = opendir(path);
	if (dp == NULL)
	{
		return (str);
	}
	while ((dirp = readdir(dp)) != NULL)
	{
		if (!(_strcmp(dirp->d_name, cmd)))
		{
			str = path;
			break;
		}
	}
	closedir(dp);
	return (str);
}

