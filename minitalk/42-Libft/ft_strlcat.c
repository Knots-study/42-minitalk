/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 07:06:54 by knottey           #+#    #+#             */
/*   Updated: 2023/05/10 07:06:54 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (src_length);
	dst_length = ft_strlen(dst);
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	ft_strlcpy(dst + dst_length, src, dstsize - dst_length);
	return (dst_length + src_length);
}
