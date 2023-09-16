/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:32:11 by knottey           #+#    #+#             */
/*   Updated: 2023/05/18 23:44:06 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_count_words(const char *str, char c)
{
	size_t	idx;
	size_t	count;
	int		word_count_flag;

	idx = 0;
	count = 0;
	word_count_flag = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] != c)
		{
			if (word_count_flag == 0)
			{
				count++;
				word_count_flag = 1;
			}
		}
		else
			word_count_flag = 0;
		idx++;
	}
	return (count);
}

static size_t	word_strlen(const char **str, char c)
{
	size_t	length;
	size_t	idx;

	length = 0;
	idx = 0;
	while (**str != '\0' && **str == c)
		(*str)++;
	while ((*str)[idx] != '\0' && !((*str)[idx] == c))
	{
		length++;
		idx++;
	}
	return (length);
}

static int	check_free(char **memory, size_t count)
{
	size_t	i;

	if (memory[count] == NULL)
	{
		i = 0;
		while (i < count)
		{
			free(memory[i]);
			i++;
		}
		free(memory);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_length;
	size_t	count_words;
	size_t	i;

	if (s == NULL)
		return (NULL);
	count_words = split_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < count_words)
	{
		word_length = word_strlen(&s, c);
		result[i] = (char *)malloc(sizeof(char) * (word_length + 1));
		if (check_free(result, i))
			return (NULL);
		ft_strlcpy(result[i], s, word_length + 1);
		s += word_length;
		i++;
	}
	result[i] = NULL;
	return (result);
}
