/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:19:03 by knottey           #+#    #+#             */
/*   Updated: 2023/09/16 13:33:02 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(pid_t pid, char c)
{
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	while (i < 8)
	{
		usleep(100);
		bit = c & (0x01 << i);
		if (bit != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	size_t	idx;

	idx = 0;
	if (argc != 3)
	{
		ft_printf("\x1b[31mEnter collect formats!\n\x1b[0m");
		ft_printf("\x1b[31mex)./client \"PID\" \"Message\" \n\x1b[0m");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][idx] != '\0')
	{
		ft_send_bits(pid, argv[2][idx]);
		idx++;
	}
	ft_send_bits(pid, '\n');
	return (0);
}
