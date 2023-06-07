/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:19:00 by knottey           #+#    #+#             */
/*   Updated: 2023/06/08 01:32:38 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 1)
	{
		printf("\x1b[31mEnter ./server!\n\x1b[0m");
		return (0);
	}
	pid = getpid();
}