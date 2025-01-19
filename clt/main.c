#include "../include/minitalk.h"

volatile sig_atomic_t g_server = BUSY;

void	end_handler(int signal)
{
	write(0, "Received!\n", 10);
	exit(0);
}

void	ack_handler(int signal)
{
	 g_server = READY;
}

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = 0;

	while (bit < CHAR_BIT)
	{
		if (c & (0b10000000 >> bit))
			Kill(pid, SIGUSR1);
		else
			Kill(pid, SIGUSR2);
		bit++;

		while (BUSY == g_server)
			usleep(42);

		g_server = BUSY;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	int	i;

	if (ac != 3)
	{
		write(0, "Wrong argument\n", 15);
		return (-1);
	}
	pid = atoi(av[1]);
	message = av[2];

	Signal(SIGUSR1, ack_handler, false);
	Signal(SIGUSR2, end_handler, false);

	i = 0;
	while (message[i])
	{
		send_char(message[i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
