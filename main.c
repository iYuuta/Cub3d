/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:02:28 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/17 18:33:57 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	render(t_data *data)
{
	(void)data;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	ft_exit(data->mlx);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	ft_exit(data->win);
	mlx_hook(data->win, CLOSE_BUTTON, 0, close_window, data);
	mlx_key_hook(data->win, key_hook, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_map(argc, argv, &data);
	init_data(&data);
	render(&data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
