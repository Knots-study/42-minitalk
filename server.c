/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:19:00 by knottey           #+#    #+#             */
/*   Updated: 2023/09/16 14:44:54 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signum)
{
	static int	bit;
	static int	print_char;

	if (signum == SIGUSR1)
		print_char |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", print_char);
		bit = 0;
		print_char = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_printf("\x1b[31mEnter ./server!\n\x1b[0m");
		return (0);
	}
	else
	{
		pid = getpid();
		ft_printf("PID = %d\n", pid);
		if (sigemptyset(&sa.sa_mask) == -1)
			exit(1);
		sa.sa_handler = ft_handler;
		sa.sa_flags = 0;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			exit(1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(1);
		while (true)
			pause();
	}
	return (0);
}
