/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:45:42 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/18 16:54:29 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

int	close_window(t_data *data)
{
	ft_lstclear(&(data->map.lines), free);
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	return (0);
}
