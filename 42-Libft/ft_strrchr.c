/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 07:10:07 by knottey           #+#    #+#             */
/*   Updated: 2023/05/10 07:10:07 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			idx;

	if (s == NULL)
		return (NULL);
	idx = ft_strlen(s) + 1;
	while (idx > 0)
	{
		idx--;
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
	}
	return (NULL);
}
