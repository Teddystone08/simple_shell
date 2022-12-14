#include "main.h"
/**
 * int main - main entering
 * @argc: argument command
 * @argv: argument vector
 * @envp: enviroment variable position
 * Return: always 0
 */
int main(int argc, char **argv, char **envp)
{
	int i;
	for (i = 0; envp[i] != NULL; i++)
	{

		printf("%s\n", envp[i]);
		getchar();
	}
	return 0;
}
