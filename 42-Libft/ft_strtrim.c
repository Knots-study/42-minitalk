/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 07:09:32 by knottey           #+#    #+#             */
/*   Updated: 2023/05/10 07:09:32 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_str;
	size_t	first_idx;
	size_t	last_idx;

	if (s1 == NULL || set == NULL)
		return (NULL);
	first_idx = 0;
	last_idx = ft_strlen(s1) - 1;
	while (s1[first_idx] && ft_strchr(set, s1[first_idx]))
		first_idx++;
	while (s1[last_idx] && ft_strrchr(set, s1[last_idx]))
		last_idx--;
	trim_str = ft_substr(s1, first_idx, last_idx - first_idx + 1);
	return (trim_str);
}
