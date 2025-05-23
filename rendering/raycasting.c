/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:49:53 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/23 13:09:58 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

int	is_out_of_bound(t_map map, int x, int y)
{
	if (y < 0 || y >= map.length)
		return (1);
	if (x < 0 || x >= (int)ft_strlen(map.map[y]))
		return (1);
	return (0);
}

void	math_init(t_cube *cube, float new_angle)
{
	cube->ray.x_dir = cos(new_angle);
	cube->ray.y_dir = sin(new_angle);
	if (cube->ray.x_dir < 0)
		cube->ray.x_step = -1;
	else
		cube->ray.x_step = 1;
	if (cube->ray.y_dir < 0)
		cube->ray.y_step = -1;
	else
		cube->ray.y_step = 1;
	cube->ray.x_dist = fabs(TILE_SIZE / cube->ray.x_dir);
	cube->ray.y_dist = fabs(TILE_SIZE / cube->ray.y_dir);
	cube->ray.curr_x = (int)(cube->player.x / TILE_SIZE);
	cube->ray.curr_y = (int)(cube->player.y / TILE_SIZE);
}

void	skip_first_tile(t_cube *cube, float new_angle)
{
	math_init(cube, new_angle);
	if (cube->ray.x_dir < 0)
		cube->ray.x_side_dis = (cube->player.x - cube->ray.curr_x * TILE_SIZE)
			/ -cube->ray.x_dir;
	else
		cube->ray.x_side_dis = ((cube->ray.curr_x + 1) * TILE_SIZE
				- cube->player.x) / cube->ray.x_dir;
	if (cube->ray.y_dir < 0)
		cube->ray.y_side_dis = (cube->player.y - cube->ray.curr_y * TILE_SIZE)
			/ -cube->ray.y_dir;
	else
		cube->ray.y_side_dis = ((cube->ray.curr_y + 1) * TILE_SIZE
				- cube->player.y) / cube->ray.y_dir;
	cube->ray.side = 1;
	if (cube->ray.x_side_dis < cube->ray.y_side_dis)
		cube->ray.side = 0;
}

void	raycasting(t_cube *cube, float new_angle)
{
	skip_first_tile(cube, new_angle);
	while (1)
	{
		if (cube->ray.x_side_dis < cube->ray.y_side_dis)
		{
			cube->ray.x_side_dis += cube->ray.x_dist;
			cube->ray.curr_x += cube->ray.x_step;
			cube->ray.side = 0;
		}
		else
		{
			cube->ray.y_side_dis += cube->ray.y_dist;
			cube->ray.curr_y += cube->ray.y_step;
			cube->ray.side = 1;
		}
		if (is_out_of_bound(cube->map, cube->ray.curr_x, cube->ray.curr_y))
			break ;
		if (ft_isin(cube->map.map[cube->ray.curr_y][cube->ray.curr_x], "10 "))
		{
			cube->ray.dist = cube->ray.x_side_dis - cube->ray.x_dist;
			if (cube->ray.side == 1)
				cube->ray.dist = cube->ray.y_side_dis - cube->ray.y_dist;
			break ;
		}
	}
}
