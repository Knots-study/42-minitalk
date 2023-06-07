/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:19:00 by knottey           #+#    #+#             */
/*   Updated: 2023/06/08 04:02:56 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_handler(int signum)
{
	static int	bit;
	static int	print_char;

	if (signum == SIGUSR1)
		print_char |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", print_char);
		//何回も関数を呼び出すので、static変数にしないと毎回0に書き変わってしまう
		bit = 0;
		print_char = 0;
	}
}

int main(int argc, char *argv[])
{
	pid_t	pid;
	struct 	sigaction sigact;

	if (argc != 1)
	{
		printf("\x1b[31mEnter ./server!\n\x1b[0m");
		return (1);
	}
	pid = getpid();
	printf("PID = %d\n", pid);
	sigact = (struct sigaction){0};
	sigact.sa_handler = &ft_handler;
	sigemptyset(&sigact.sa_mask);//エラーハンドリング必要
    sigact.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sigact, NULL);//エラーハンドリング必要
		sigaction(SIGUSR2, &sigact, NULL);//エラーハンドリング必要
		pause ();
	}
	return (0);
}