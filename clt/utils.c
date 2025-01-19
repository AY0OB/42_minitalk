#include "../include/minitalk.h"

void	Kill(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		write(0, "kill failed\n", 12);
		exit(0);
	}
}
