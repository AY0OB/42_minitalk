/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:46:28 by amairia           #+#    #+#             */
/*   Updated: 2025/01/20 18:48:23 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft_with_gnl_printf/libft.h"

enum
{
	READY,
	BUSY,
};

void	ft_signal(int signal, void *handler, bool use_siginfo);
void	ft_kill(pid_t pid, int signal);

#endif
