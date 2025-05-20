/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:45:42 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 15:50:15 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

int	close_window(t_cube *cube)
{
	ft_lstclear(&(cube->lines), free);
	free(cube->no);
	free(cube->so);
	free(cube->we);
	free(cube->ea);
	free(cube->f);
	free(cube->c);
	mlx_destroy_window(cube->mlx, cube->win);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_cube *cube)
{
	if (keycode == ESC)
		close_window(cube);
	return (0);
}
