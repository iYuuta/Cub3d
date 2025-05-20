/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:51:25 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/18 16:51:34 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		r;

	r = 0;
	i = 0;
	while (r == 0 && i < n)
	{
		if (!(s1[i] || s2[i]))
			break ;
		r = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (r);
}
