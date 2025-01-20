/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:27:36 by amairia           #+#    #+#             */
/*   Updated: 2025/01/20 18:45:19 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_server = BUSY;

void	end_handler(int signal)
{
	(void)signal;
	write(0, "Received!\n", 10);
	exit(0);
}

void	ack_handler(int signal)
{
	(void)signal;
	g_server = READY;
}

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0b10000000 >> bit))
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
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
	int		i;

	if (ac != 3)
	{
		write(0, "Wrong argument\n", 15);
		return (-1);
	}
	pid = atoi(av[1]);
	message = av[2];
	ft_signal(SIGUSR1, ack_handler, false);
	ft_signal(SIGUSR2, end_handler, false);
	i = 0;
	while (message[i])
	{
		send_char(message[i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
