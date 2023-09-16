/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 07:03:46 by knottey           #+#    #+#             */
/*   Updated: 2023/05/10 07:03:46 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	idx;

	if (s == NULL)
		return ;
	idx = 0;
	while (s[idx] != '\0')
	{
		ft_putchar_fd(s[idx], fd);
		idx++;
	}
}
