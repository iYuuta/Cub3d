#include "Cupid.h"

static void	destroy_texture(void *mlx, void *texture)
{
	if (texture)
		mlx_destroy_image(mlx, texture);
}

static void	free_texture(t_cube *cube)
{
	int	i;

	destroy_texture(cube->mlx, cube->no.texture);
	destroy_texture(cube->mlx, cube->so.texture);
	destroy_texture(cube->mlx, cube->we.texture);
	destroy_texture(cube->mlx, cube->ea.texture);
	destroy_texture(cube->mlx, cube->image.texture);
	i = 0;
	while (i < 11)
	{
		destroy_texture(cube->mlx, cube->door[i].texture);
		i++;
	}
}

void	ft_exit(int exit_status, t_cube *cube)
{
	ft_free();
	if (cube)
	{
		free_texture(cube);
		if (cube->mlx && cube->win)
			mlx_destroy_window(cube->mlx, cube->win);
		if (cube->mlx)
			mlx_destroy_display(cube->mlx);
	}
	exit(exit_status);
}
