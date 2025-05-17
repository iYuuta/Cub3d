/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:01:36 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/17 16:05:11 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*s3_start;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	s3_start = s3;
	while (*s1)
		*(s3++) = *(s1++);
	while (*s2)
		*(s3++) = *(s2++);
	*s3 = '\0';
	return (s3_start);
}
