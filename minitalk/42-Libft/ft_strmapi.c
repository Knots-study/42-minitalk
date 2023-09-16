/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:00:27 by knottey           #+#    #+#             */
/*   Updated: 2023/05/18 11:47:40 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	idx;
	size_t	word_length;

	if (s == NULL || f == NULL)
		return (NULL);
	word_length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (word_length + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (idx < word_length)
	{
		str[idx] = f(idx, s[idx]);
		idx++;
	}
	return (str);
}
