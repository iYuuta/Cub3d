/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:45:42 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/23 12:58:39 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

int	close_window(t_cube *cube)
{
	mlx_destroy_image(cube->mlx, cube->no.texture);
	mlx_destroy_image(cube->mlx, cube->so.texture);
	mlx_destroy_image(cube->mlx, cube->we.texture);
	mlx_destroy_image(cube->mlx, cube->ea.texture);
	mlx_destroy_window(cube->mlx, cube->win);
	ft_exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_cube *cube)
{
	if (keycode == ESC)
		close_window(cube);
	return (0);
}
