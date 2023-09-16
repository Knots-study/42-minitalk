/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 05:01:00 by knottey           #+#    #+#             */
/*   Updated: 2023/05/01 12:36:30 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			length;
	unsigned char	*dest;

	length = 0;
	dest = (unsigned char *)s;
	while (length < n)
	{
		dest[length] = (unsigned char)c;
		length++;
	}
	return (dest);
}
