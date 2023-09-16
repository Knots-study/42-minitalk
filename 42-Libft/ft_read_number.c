/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:23:42 by knottey           #+#    #+#             */
/*   Updated: 2023/09/16 14:42:34 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read_number(const char *str, int *flag)
{
	long long int	sign;
	long long int	ans;

	sign = ft_space_sign(str, &str);
	ans = 0;
	while (ft_isdigit(*str))
	{
		if ((ans > INT_MAX) || (ans < INT_MIN))
		{
			*flag = -1;
			break ;
		}
		ans *= 10;
		ans += *str - '0';
		str++;
	}
	if (*str != '\0')
		*flag = -1;
	return ((int)(ans * sign));
}
