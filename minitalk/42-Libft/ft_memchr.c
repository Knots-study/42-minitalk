/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 06:58:48 by knottey           #+#    #+#             */
/*   Updated: 2023/05/10 06:58:48 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				idx;
	const unsigned char	*cus;
	unsigned char		uc;

	idx = 0;
	cus = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (idx < n)
	{
		if (cus[idx] == uc)
			return ((void *)(cus + idx));
		idx++;
	}
	return (NULL);
}
