/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:02:28 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/23 13:06:32 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	init_data(t_cube *cube)
{
	cube->player.x = 0;
	cube->player.y = 0;
	cube->player.h_angle = 0.002;
	cube->player.v_angle = 0;
	cube->player.x = 1 * 128;
	cube->player.y = 2 * 128;
	cube->ray.x_dir = 0;
	cube->ray.y_dir = 0;
	cube->ray.x_dist = 0;
	cube->ray.y_dist = 0;
	cube->ray.x_step = 0;
	cube->ray.y_step = 0;
	cube->ray.x_side_dis = 0;
	cube->ray.y_side_dis = 0;
	cube->ray.curr_x = 0;
	cube->ray.curr_y = 0;
}

void	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		ft_exit(EXIT_FAILURE);
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, TITLE);
	if (!cube->win)
		ft_exit(EXIT_FAILURE);
	mlx_hook(cube->win, CLOSE_BUTTON, 0, close_window, cube);
	mlx_key_hook(cube->win, key_hook, cube);
	mlx_hook(cube->win, 2, 0, detect_move, cube);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_mlx(&cube);
	parse(argc, argv, &cube);
	render(&cube);
	mlx_loop(cube.mlx);
	ft_free();
	return (EXIT_SUCCESS);
}
