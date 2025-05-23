/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:41:08 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/23 13:03:58 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

int	is_move_valid(t_map map, float tile_x, float tile_y)
{
	int	x;
	int	y;

	x = (int)(tile_x / TILE_SIZE);
	y = (int)(tile_y / TILE_SIZE);
	if (y < 0 || y >= map.length)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(map.map[y]))
		return (0);
	if (ft_strchr("1 ", map.map[y][x]))
		return (0);
	return (1);
}

int	move_player(t_cube *cube, float new_x, float new_y)
{
	if (!is_move_valid(cube->map, new_x, new_y))
		return (0);
	cube->player.x = new_x;
	cube->player.y = new_y;
	return (1);
}

float	fix_angle(float angle)
{
	angle = fmod(angle, PI * 2);
	if (angle < 0)
		angle += PI * 2;
	return (angle);
}

int	check_angle(t_cube *cube, int move)
{
	if (move == UP && cube->player.v_angle > ((PI / 4) * -1))
		cube->player.v_angle -= 0.08;
	else if (move == LEFT)
		cube->player.h_angle -= 0.08;
	else if (move == DOWN && cube->player.v_angle < (PI / 4))
		cube->player.v_angle += 0.08;
	else if (move == RIGHT)
		cube->player.h_angle += 0.08;
	else
		return (0);
	if (cube->player.h_angle <= (2 * PI) * -1 || cube->player.h_angle >= 2 * PI)
		cube->player.h_angle = fix_angle(cube->player.h_angle);
	return (1);
}

int	detect_move(int move, void *ptr)
{
	t_cube	*cube;
	float	x;
	float	y;

	cube = (t_cube *)ptr;
	if (move == ESC)
		exit(0);
	x = cos(cube->player.h_angle) * 8;
	y = sin(cube->player.h_angle) * 8;
	if (check_angle(cube, move))
		return (render(cube), 0);
	if (move == W)
		move_player(cube, cube->player.x + x, cube->player.y + y);
	if (move == S)
		move_player(cube, cube->player.x - x, cube->player.y - y);
	if (move == D)
		move_player(cube, cube->player.x - y, cube->player.y + x);
	if (move == A)
		move_player(cube, cube->player.x + y, cube->player.y - x);
	render(cube);
	return (0);
}
