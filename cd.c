#include "main.h"


/**
 * getenv_val - get the current working dir
 * @str: string to compare
 * @env: environment
 *
 * Return: directory name (success), NULL (fail)
 */
char *getenv_val(char *str, char **env)
{
	int i, j, len = 0, bk = 0;
	char *pwd = NULL, *ptr = NULL;

	pwd = _getenv(str, env);
	if (pwd != NULL)
	{
		for (i = 0; pwd[i] != '='; i++)
		{
		}
		i++;

		len = _strlen(pwd);
		bk = i;
		i = len - bk;

		ptr = (char *)calloc(i + 1, sizeof(char));
		if (ptr != NULL)
		{
			for (j = 0; j < i; j++, bk++)
			{
				ptr[j] = pwd[bk];
			}
			free(pwd);
			return (ptr);
		}
	}
	return (pwd);
}


/**
 * chg_dir - change current working directory
 * Description: changes dir based on parameter
 * @ptr: new directory
 * @shell_name: string
 * @cmd_name: string
 * @line: integer
 * Return: 0 (success), -1 (fail)
 */
int chg_dir(char *shell_name, char *cmd_name, int line, char *ptr)
{
	int i, j = 0;
	DIR *dir;

	dir = opendir(ptr);
	if (dir == NULL)
	{
		if (errno == EACCES)
		{
			error_print(shell_name, cmd_name, line,
					DIR_PERMISSION_ERROR);
		}
		else if (errno == ENOENT)
		{
			error_print(shell_name, cmd_name, line,
					DIR_EXIST_ERROR);
		}
		j = -1;
	}
	else
	{
		closedir(dir);
		i = chdir(ptr);
		if (i != 0)
		{
			if (errno == ENOTDIR)
			{
				error_print(shell_name, cmd_name, line,
						CHG_DIR_PATH_ERROR);
			}
			else if (errno == ENAMETOOLONG)
			{
				error_print(shell_name, cmd_name, line,
						CHG_DIR_NAME_ERROR);
			}
			j = -1;
		}
	}
	return (j);
}


/**
 * check_prev_cmd - checks for '-' command with cd
 *
 * Description: updates the argument passed to
 * previous directory name stored in "old"
 * @new: string
 * @n: string
 * @old: string
 * @env: environment
 * Return: Nothing
 */
void check_prev_cmd(char *new, char **n, char *old, char **env)
{
	char *temp = NULL;

	if (_strcmp(new, "-") == 0)
	{
		*n = old;
		printf("%s\n", old);
	}
	else if (_strcmp(new, "~") == 0)
	{
		temp = getenv_val("HOME", env);
		*n = temp;
	}
}

/**
 * update_pwd - updates old and current directory / env
 * Description: it updates the old and current directory names and
 * also updates the entries of PWD and OLDPWD environ strings values
 *
 * @old: previous directory
 * @new: current directory
 * @shell_name: name used to call shell
 * @cmd_name: command passed
 * @line: line number
 * @cd_status: flag
 * Return: Nothing
 */
void update_pwd(char *shell_name, char *cmd_name, int line,
		int cd_status, char **old, char **new)
{
	int len = 0, j = 0, k = 0;
	char *pwd = NULL, *buf = NULL, *tmp = NULL;

	if (cd_status == 0)
	{
		pwd = getcwd(buf, 0);
		if (pwd == NULL)
		{
			error_print(shell_name, cmd_name, line, GET_CWD_ERROR);
		}
		else
		{
			len = _strlen(pwd);
			tmp = *old;
			*old = *new, *new = pwd;
			free(tmp);
			k = setenv("PWD", *new, len);
			len = _strlen(*old);
			j = setenv("OLDPWD", *old, len);
			if (j == -1 || k == -1)
			{
				error_print(shell_name, cmd_name, line, SET_ENV_ERROR);
				return;
			}
		}
	}
}

