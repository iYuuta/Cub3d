#include "Cupid.h"

int	is_out_of_bound(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->length)
		return (1);
	if (x < 0 || x >= (int)ft_strlen(map->map[y]))
		return (1);
	return (0);
}

void	get_direction(t_cube *cub)
{
	float	wall_x;

	cub->ray.dist = cub->ray.x_side_dis - cub->ray.x_dist;
	if (cub->ray.side == 1)
	{
		cub->ray.dist = cub->ray.y_side_dis - cub->ray.y_dist;
		wall_x = cub->player.x + cub->ray.dist * cub->ray.x_dir;
		if (cub->map.map[cub->ray.curr_y][cub->ray.curr_x] == 'D')
			cub->column.wall = DOOR;
		else if (cub->ray.y_dir < 0)
			cub->column.wall = NORTH;
		else
			cub->column.wall = SOUTH;
	}
	else
	{
		wall_x = cub->player.y + cub->ray.dist * cub->ray.y_dir;
		if (cub->map.map[cub->ray.curr_y][cub->ray.curr_x] == 'D')
			cub->column.wall = DOOR;
		else if (cub->ray.x_dir < 0)
			cub->column.wall = WEST;
		else
			cub->column.wall = EAST;
	}
	wall_x = fmod(wall_x, TILE_SIZE);
	if (wall_x < 0)
		wall_x += TILE_SIZE;
	cub->column.tex_x = (int)(wall_x * (64 / (float)TILE_SIZE));
}

void	math_init(t_cube *cub, float new_angle)
{
	cub->ray.x_dir = cos(new_angle);
	cub->ray.y_dir = sin(new_angle);
	if (cub->ray.x_dir < 0)
		cub->ray.x_step = -1;
	else
		cub->ray.x_step = 1;
	if (cub->ray.y_dir < 0)
		cub->ray.y_step = -1;
	else
		cub->ray.y_step = 1;
	cub->ray.x_dist = fabs(TILE_SIZE / cub->ray.x_dir);
	cub->ray.y_dist = fabs(TILE_SIZE / cub->ray.y_dir);
	cub->ray.curr_x = (int)(cub->player.x / TILE_SIZE);
	cub->ray.curr_y = (int)(cub->player.y / TILE_SIZE);
}

void	skip_first_tile(t_cube *cub, float new_angle)
{
	math_init(cub, new_angle);
	if (cub->ray.x_dir < 0)
		cub->ray.x_side_dis = (cub->player.x - cub->ray.curr_x * TILE_SIZE)
			/ -cub->ray.x_dir;
	else
		cub->ray.x_side_dis = ((cub->ray.curr_x + 1)
				* TILE_SIZE - cub->player.x) / cub->ray.x_dir;
	if (cub->ray.y_dir < 0)
		cub->ray.y_side_dis = (cub->player.y - cub->ray.curr_y * TILE_SIZE)
			/ -cub->ray.y_dir;
	else
		cub->ray.y_side_dis = ((cub->ray.curr_y + 1)
				* TILE_SIZE - cub->player.y) / cub->ray.y_dir;
	cub->ray.side = 1;
	if (cub->ray.x_side_dis < cub->ray.y_side_dis)
		cub->ray.side = 0;
}

void	ray_casting(t_cube *cub, float new_angle)
{
	skip_first_tile(cub, new_angle);
	while (1)
	{
		if (cub->ray.x_side_dis < cub->ray.y_side_dis)
		{
			cub->ray.x_side_dis += cub->ray.x_dist;
			cub->ray.curr_x += cub->ray.x_step;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.y_side_dis += cub->ray.y_dist;
			cub->ray.curr_y += cub->ray.y_step;
			cub->ray.side = 1;
		}
		if (is_out_of_bound(&(cub->map), cub->ray.curr_x, cub->ray.curr_y))
			break ;
		if (ft_strchr("1D ", cub->map.map[cub->ray.curr_y][cub->ray.curr_x]))
		{
			get_direction(cub);
			break ;
		}
	}
}
