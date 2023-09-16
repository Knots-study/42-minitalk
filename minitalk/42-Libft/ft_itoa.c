/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:34:32 by knottey           #+#    #+#             */
/*   Updated: 2023/05/18 09:19:30 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long long int n)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*ans;
	size_t			elem_length;
	long long int	lln;

	lln = (long long int)n;
	elem_length = ft_intlen(lln);
	ans = (char *)malloc(sizeof(char) * (elem_length + 1));
	if (ans == NULL)
		return (NULL);
	ans[elem_length] = '\0';
	if (n == 0)
		ans[0] = '0';
	else if (n < 0)
	{
		ans[0] = '-';
		lln *= -1;
	}
	while (lln > 0)
	{
		ans[elem_length - 1] = lln % 10 + '0';
		lln /= 10;
		elem_length--;
	}
	return (ans);
}
