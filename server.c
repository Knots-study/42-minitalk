/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:19:00 by knottey           #+#    #+#             */
/*   Updated: 2023/06/21 17:02:05 by knottey          ###   ########.fr       */
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
	struct 	sigaction sa;

	if (argc != 1)
	{
		printf("\x1b[31mEnter ./server!\n\x1b[0m");
		return (0);
	}
	pid = getpid();
	printf("PID = %d\n", pid);
	sigemptyset(&sa.sa_mask);//エラーハンドリング必要
	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);//エラーハンドリング必要
		sigaction(SIGUSR2, &sa, NULL);//エラーハンドリング必要
		// signal(SIGUSR1, ft_handler);
		// signal(SIGUSR2, ft_handler);
		// pause ();
	}
	return (0);
}