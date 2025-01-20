/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:48:37 by amairia           #+#    #+#             */
/*   Updated: 2025/01/20 18:48:38 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_kill(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		write(0, "kill failed\n", 12);
		exit(0);
	}
}

void	ft_signal(int signal, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_sigaction = 0;
	sa.sa_handler = 0;
	if (use_siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(signal, &sa, NULL) < 0)
	{
		perror("Sigaction failed\n");
		exit(0);
	}
}
