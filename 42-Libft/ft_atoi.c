/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:22:35 by knottey           #+#    #+#             */
/*   Updated: 2023/09/16 14:50:43 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

long long int	ft_space_sign(const char *str, const char **endptr)
{
	long long int	sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	*endptr = str;
	return (sign);
}

int	ft_atoi(const char *str)
{
	long long int	sign;
	long long int	ans;

	sign = ft_space_sign(str, &str);
	ans = 0;
	while (ft_isdigit(*str))
	{
		if ((ans * sign) > (LONG_MAX / 10))
			return ((int)(LONG_MAX));
		if ((ans * sign) == (LONG_MAX / 10) && (*str - '0') > (LONG_MAX % 10))
			return ((int)(LONG_MAX));
		if ((ans * sign) < (LONG_MIN / 10))
			return ((int)LONG_MIN);
		if ((ans * sign) == (LONG_MIN / 10) && ('0' - *str) < (LONG_MIN % 10))
			return ((int)LONG_MIN);
		ans *= 10;
		ans += *str - '0';
		str++;
	}
	return ((int)(ans * sign));
}
