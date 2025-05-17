/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:01:01 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/17 17:26:41 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	ft_putendl_fd(char *s, int fd)
{
	ssize_t	ret;

	if (!s)
		return ;
	while (*s)
		ret = write(fd, s++, 1);
	ret = write(fd, "\n", 1);
	(void)ret;
}
