#include "Cupid.h"

void	get_player_position(t_cube *cub, int *x, int *y)
{
	*y = 0;
	while (cub->map.map[*y])
	{
		*x = 0;
		while (cub->map.map[*y][*x])
		{
			if (ft_strchr("ENSW", cub->map.map[*y][*x]))
			{
				if (cub->map.map[*y][*x] == 'E')
					cub->player.h_angle = 0.001;
				else if (cub->map.map[*y][*x] == 'S')
					cub->player.h_angle = PI / 2;
				else if (cub->map.map[*y][*x] == 'W')
					cub->player.h_angle = PI;
				else
					cub->player.h_angle = (PI / 2) * 3;
				return ;
			}
			(*x)++;
		}
		(*y)++;
	}
}

void	init_data(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_position(cube, &x, &y);
	cube->player.v_angle = HEIGHT / 2;
	cube->player.x = (x * TILE_SIZE) + 32;
	cube->player.y = (y * TILE_SIZE) + 32;
	init_minimap(cube);
}

void	init_mlx(t_cube *cube)
{
	ft_memset(cube, 0 , sizeof(t_cube));
	cube->mlx = mlx_init();
	if (!cube->mlx)
		ft_error("Failed to init mlx", cube);
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, TITLE);
	if (!cube->win)
		ft_error("Failed to init window", cube);
	cube->image.texture = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->image.texture)
		ft_error("Failed to init image", cube);
	cube->image.addr = mlx_get_data_addr(cube->image.texture,
			&(cube->image.bits_per_pixel), &(cube->image.size_line),
			&(cube->image.endian));
	if (!cube->image.addr)
		ft_error("Failed to init image address", cube);
	cube->key.door_status = 0;
	cube->sprite_timer = current_time();
	mlx_hook(cube->win, CLOSE_BUTTON, 0, close_window, cube);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_mlx(&cube);
	parse(argc, argv, &cube);
	mlx_loop(cube.mlx);
	ft_free();
	return (EXIT_SUCCESS);
}
