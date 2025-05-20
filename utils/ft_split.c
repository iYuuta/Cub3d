/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:38:59 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 03:12:08 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_copy(char const *start, char const *end)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(end - start + 1);
	if (!copy)
		return (NULL);
	while (start < end)
	{
		copy[i] = *start;
		start++;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_free_split(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	char const	*start;
	int			i;

	arr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			start = s;
			while (*s && *s != c)
				s++;
			arr[i] = ft_copy(start, s);
			if (!arr[i])
				return (ft_free_split(arr, i));
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
