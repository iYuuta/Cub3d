/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:02:28 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 16:48:52 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	render(t_cube *cube)
{
	(void)cube;
}

void	init_data(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		ft_exit(EXIT_FAILURE);
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, TITLE);
	if (!cube->win)
		ft_exit(EXIT_FAILURE);
	mlx_hook(cube->win, CLOSE_BUTTON, 0, close_window, cube);
	mlx_key_hook(cube->win, key_hook, cube);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_data(&cube);
	check_map(argc, argv, &cube);
	render(&cube);
	mlx_loop(cube.mlx);
	return (EXIT_SUCCESS);
}
