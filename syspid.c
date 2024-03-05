#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * get_p_id - function that accur the process id
 * Return: void
 *
 */

int main(void)
{
	pid_t get_p_id = getppid();
	pid_t get_pc_id = getpid();
	printf("Process ID is: %d\n", get_p_id);
	printf("Process child ID id: %d\n", get_pc_id);
	return (0);
}
