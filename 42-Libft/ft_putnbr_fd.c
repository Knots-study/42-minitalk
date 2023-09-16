/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 07:02:55 by knottey           #+#    #+#             */
/*   Updated: 2023/05/10 07:02:55 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			cn;
	long long int	lln;

	lln = (long long int)n;
	if (lln < 0)
	{
		ft_putchar_fd('-', fd);
		lln *= -1;
	}
	if (lln >= 10)
		ft_putnbr_fd((int)(lln / 10), fd);
	cn = lln % 10 + '0';
	ft_putchar_fd(cn, fd);
}
