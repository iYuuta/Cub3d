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

int pressed(int key, void *ptr)
{
	t_cube *cub;

	cub = (t_cube *)ptr;
	if (key == ESC)
		cub->key.esc = 1;
	else if (key == W)
		cub->key.w = 1;
	else if (key == D)
		cub->key.d = 1;
	else if (key == S)
		cub->key.s = 1;
	else if (key == A)
		cub->key.a = 1;
	else if (key == UP)
		cub->key.up = 1;
	else if (key == DOWN)
		cub->key.down = 1;
	else if (key == LEFT)
		cub->key.left = 1;
	else if (key == RIGHT)
		cub->key.right = 1;
	return (0);
}

int released(int key, void *ptr)
{
	t_cube *cub;

	cub = (t_cube *)ptr;
	if (key == W)
		cub->key.w = 0;
	else if (key == D)
		cub->key.d = 0;
	else if (key == S)
		cub->key.s = 0;
	else if (key == A)
		cub->key.a = 0;
	else if (key == UP)
		cub->key.up = 0;
	else if (key == DOWN)
		cub->key.down = 0;
	else if (key == LEFT)
		cub->key.left = 0;
	else if (key == RIGHT)
		cub->key.right = 0;
	return (0);
}
