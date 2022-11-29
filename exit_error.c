#include "main.h"


/**
 * exit_feof - check for end of file and exit program
 * @old: old pwd
 * @new: current pwd
 * @lineptr: line from standard input
 * @path_line: pointer to path environment variable
 * @flag: call integer for exit call
 *
 * Return: Nothing
 */
void exit_feof(char *old, char *new, char *lineptr, char *path_line, int flag)
{
	if (feof(stdin))
	{
		free(lineptr);
		free(old);
		free(new);
		free(path_line);
		if (flag == 1)
		{
			exit_call("hsh", 1, NULL, 1);
		}
		else
		{
			exit_call("hsh", 1, NULL, 88);
		}
	}
}



/**
 * free_env - frees memory of current and old directory
 *
 * @curr: current directory
 * @old: previous directory
 * Return: Nothing.
 */
void free_env(char *old, char *curr)
{
	free(old);
	free(curr);
}


/**
 * error_print - prints string to standard error
 *
 * @str: message
 * @shell_name: string
 * @cmd_name: string
 * @line: integer
 * Return: Nothing.
 */
void error_print(char *shell_name, char *cmd_name, int line, char *str)
{
	if (str != NULL)
	{
		if (_strlen(str) > 0)
		{
			dprintf(STDERR_FILENO, "%s: %i: %s: %s\n",
					shell_name, line, cmd_name, str);
		}
	}
}



/**
 * exit_call - closes a program
 * @shell_name: string
 * @line: integer
 * @call: integer
 * @str: string
 *
 * Return: Nothing
 */
void exit_call(char *shell_name, int line, char *str, int call)
{
	switch (call)
	{
		case 99:
			printf("%s: %d: %s\n", shell_name, line, str);
			break;
		case 88:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("\n");
			exit(EXIT_SUCCESS);
	}
}

