/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:02:28 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/17 16:05:15 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"
#include <stdio.h>

void	ft_error(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	valid_map_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i--] == 'b' && str[i--] == 'u' && str[i--] == 'c' && str[i] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;

	if (argc != 2)
		ft_error("Invalid Argument: takes one argument");
	if (!valid_map_name(argv[1]))
		ft_error("Invalid map name: must end with .ber");
	mlx = mlx_init();
	mlx_new_window(mlx, 320, 320, TITLE);
	mlx_new_image(mlx, 320, 320);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
