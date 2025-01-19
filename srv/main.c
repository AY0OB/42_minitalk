#include "../include/minitalk.h"

void	handler(int signal, siginfo_t *info, void *more)
{
	static char	c;
	static int	bit;
	static pid_t	pid;

	(void)more;
	if (info->si_pid)
		pid = info->si_pid;
	if (SIGUSR1 == signal)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == signal)
		c &= ~(0b10000000 >> bit);
	bit++;

	if (8 == bit)
	{
		bit = 0;
		if ('\0' == c)
		{
			write(0, "\n", 1);
			Kill(pid, SIGUSR2);
			return ;
		}
		write(0, &c, 1);
	}

	kill(pid, SIGUSR1);
}

int	main(void)
{
	/*	SIGUSR1 = bits 1
		SIGUSR2 = bits 2
	*/
	ft_printf("%d\n", getpid());
	
	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);

	while (1)
		pause();
	return (0);
}
