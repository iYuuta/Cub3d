/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:34:10 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/17 17:34:25 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	ft_error(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
