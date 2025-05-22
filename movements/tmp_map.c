#include "Cupid.h"

t_cub *create_map(void)
{
	t_cub *cub;

	cub = malloc(sizeof(t_cub));
	cub->player = malloc(sizeof(t_player));
	cub->player->x = 0;
	cub->player->y = 0;
	cub->player->h_angle = 0.002;
	cub->player->v_angle = 0;
	cub->player->x = 1 * 128;
	cub->player->y = 2 * 128;
	cub->ray = malloc(sizeof(t_ray));
	cub->ray->x_dir = 0;
	cub->ray->y_dir = 0;
	cub->ray->x_dist = 0;
	cub->ray->y_dist = 0;
	cub->ray->x_step = 0;
	cub->ray->y_step = 0;
	cub->ray->x_side_dis = 0;
	cub->ray->y_side_dis = 0;
	cub->ray->curr_x = 0;
	cub->ray->curr_y = 0;
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	const char *lines[] = {
		"   1111111  111111111",
		"111111001  10000001",
		"100001111111000001",
		"100001     100D001",
		"1000011111111000001",
		"10000000000000000011",
		"111111111111111111"
	};

	int rows = 7;
	cub->map = malloc(sizeof(t_map));
	if (!cub->map)
		return (NULL);

	cub->map->map = malloc(sizeof(char *) * (rows + 1));
	if (!cub->map->map)
	{
		free(cub->map);
		return (NULL);
	}
    cub->map->map[rows] = NULL;
	for (int i = 0; i < rows; i++)
	{
		cub->map->map[i] = strdup(lines[i]);
		if (!cub->map->map[i])
		{
			// cleanup on failure
			for (int j = 0; j < i; j++)
				free(cub->map->map[j]);
			free(cub->map->map);
			free(cub->map);
			return (NULL);
		}
	}
	cub->map->length = rows;
	return cub;
}
