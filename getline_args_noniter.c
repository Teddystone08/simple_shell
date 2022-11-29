#include "main.h"

/**
 * free_args_noniter - frees memory in a double pointer
 * @args: pointer to strings
 * Return: Nothing
 */
void free_args_noniter(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}


/**
 * readline_noniter - retrieves the line string with delimiter
 * @old: old pwd
 * @new: current pwd
 * @path_line: path environment variable
 *
 * Return: pointer to string (success), NULL (fail)
 */
char *readline_noniter(char *old, char *new, char *path_line)
{
	char *lineptr = NULL;
	size_t n = 0;
	int i = 0;

	i = getline(&lineptr, &n, stdin);
	if (i == -1)
	{
		exit_feof(old, new, lineptr, path_line, 88);
	}
	return (lineptr);
}


/**
 * getline_args_noniter - breaks a string into sub args with delimiter
 * @old: old pwd
 * @new: current pwd
 * @path_line: path environment variable
 *
 * Return: pointer to string args (success), NULL (fail)
 */
char **getline_args_noniter(char *old, char *new, char *path_line)
{
	char *lineptr, **args = NULL;
	char delim[] = " \t\r\a\n";

	lineptr = readline_noniter(old, new, path_line);
	if (lineptr == NULL)
	{
		return (NULL);
	}

	args = get_substrings(lineptr, delim);
	if (args == NULL)
	{
		return (NULL);
	}
	free(lineptr);
	return (args);
}

