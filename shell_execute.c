#include "main.h"

/**
 * shell_execute - executes a command given to shell
 * @args: string tokens of command
 * @shell_name: string
 * @line: integer
 * @env: environment
 *
 * Return: integer.
 */
int shell_execute(char *shell_name, int line, char **args, char **env)
{
	pid_t pid;
	int i = 0, j = 0, wait_status = 0;
	int *sign = &wait_status;
	char *temp = NULL;

	temp = args[0];
	j = access(temp, X_OK);
	if (j != -1)
	{
		pid = fork();
		if (pid == 0)
		{
			i = execve(args[0], args, env);
			if (i == -1)
			{
				error_print(shell_name, args[0], line, EXECVE_ERROR);
				return (1);
			}
		}
		else if (pid > 0)
		{
			do {
				waitpid(pid, sign, WUNTRACED);
			} while (!WIFEXITED(*sign) && !WIFSIGNALED(*sign));
		}
		else
		{
			error_print(shell_name, args[0], line, EXECVE_CHILD_ERROR);
		}
	}
	else
	{
		error_print(shell_name, temp, line, COMMAND_EXIST_ERROR);
		return (1);
	}
	return (1);
}

