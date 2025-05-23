/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:52:33 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/23 13:06:19 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	draw_angles(t_cube *cube)
{
	char	str[50];

	sprintf(str, "h_angle: %.2f", cube->player.h_angle);
	mlx_string_put(cube->mlx, cube->win, 10, 10, 0x00FF00, str);
	sprintf(str, "v_angle: %.2f", cube->player.v_angle);
	mlx_string_put(cube->mlx, cube->win, 10, 30, 0x00FF00, str);
}

void	draw_line(t_cube *cube, int x, float dir)
{
	int		y;
	float	line_hight;
	float	fix;

	y = 0;
	raycasting(cube, dir);
	fix = fix_angle(cube->player.h_angle - dir);
	line_hight = (TILE_SIZE * HEIGHT) / (cube->ray.dist * cos(fix));
	while (y < (HEIGHT - line_hight) / 2)
		mlx_pixel_put(cube->mlx, cube->win, x, y++, 0xFFFFFF);
	if (line_hight > HEIGHT)
		line_hight = HEIGHT;
	while (line_hight-- > 0)
	{
		mlx_pixel_put(cube->mlx, cube->win, x, y, 0xFF0000);
		y++;
	}
	while (y < HEIGHT)
		mlx_pixel_put(cube->mlx, cube->win, x, y++, 0x000000);
}

void	render(t_cube *cube)
{
	int		x;
	float	dir;
	float	fov;

	fov = 60 * (PI / 180);
	dir = cube->player.h_angle - (fov / 2);
	x = 0;
	while (x < WIDTH)
	{
		draw_line(cube, x, dir);
		dir += fov / WIDTH;
		x++;
	}
	draw_angles(cube);
}
