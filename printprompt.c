#include "shellmain.h"

/**
 * _prompt_wait - function the print prompt and wait for input
 * Return: void
 *
 */
void _prompt_wait(void)
{
	printf("$ ");
}

/**
 * _get_input - functiont to read user input
 *@n: size of numbers
 *@s: number on line
 *
 * Return: 0 else -1 when error
 */
int _get_input(char *s, size_t n)
{
	size_t len = 0;

	n = getline(&s, &len, stdin);
	if (n == -1)
	{
		perror("Error reading input");
		exit(EXIT_FAILURE);
	}


}
