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
	copy = (char *)ft_malloc(end - start + 1);
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

char	**ft_split(char const *s, char c)
{
	char		**arr;
	char const	*start;
	int			i;

	arr = (char **)ft_malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
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
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
