/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:40:23 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/18 16:44:52 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int	ret;

	if (!s)
		return ;
	while (*s)
		ret = write(fd, s++, 1);
	(void)ret;
}
