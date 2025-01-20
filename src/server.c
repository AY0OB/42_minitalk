/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:45:52 by amairia           #+#    #+#             */
/*   Updated: 2025/01/20 18:45:54 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signal, siginfo_t *info, void *more)
{
	static char		c;
	static int		bit;
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
			ft_kill(pid, SIGUSR2);
			return ;
		}
		write(0, &c, 1);
	}
	ft_kill(pid, SIGUSR1);
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	ft_signal(SIGUSR1, handler, true);
	ft_signal(SIGUSR2, handler, true);
	while (1)
		pause();
	return (0);
}
