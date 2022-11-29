#include "main.h"


/**
 * main - simple shell
 * @ac: number of arguments
 * @av: pointer to arguments
 * @env: environment
 *
 * Return: 0 (success), -1 (fail)
 */
int main(int ac, char **av, char **env)
{

	/* add config codes here */
	if (ac > 1)
	{
		return (0);
	}
	if (isatty(STDIN_FILENO) == 0)
	{
		printf("non-iterative\n");
		shell_routine_noniter(av[0], env);
	}
	else
	{
		printf("iterative\n");
		shell_routine(av[0], env);
	}

	return (0);
}

