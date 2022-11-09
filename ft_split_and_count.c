/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:19:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/09 08:22:33 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**free_dst(char **dst, size_t j)
{
	size_t	count;

	count = 0;
	while (count < j)
	{
		free(dst[j]);
		count++;
	}
	free(dst);
	return (dst);
}

static char	**split_helper(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 1;
	len = 0;
	dst[0] = malloc(sizeof(char));
	while (s[i] != '\0')
	{
		if (s[i] != c)
			len++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			dst[j] = malloc((len + 1) * sizeof(char));
			if (!dst[j])
				return (free_dst(dst, j));
			ft_strlcpy(dst[j], &s[i - len + 1], len + 1);
			j++;
			len = 0;
		}
		i++;
	}
	dst[j] = NULL;
	return (dst);
}

char	**ft_split_and_count(char const *s, char c, int *argc)
{
	char	**dst;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = count_word(s, c);
	if (count == 0)
		return (NULL);
	dst = malloc((count + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	if (!split_helper(dst, s, c))
		return (NULL);
	*argc = count + 1;
	return (dst);
}
