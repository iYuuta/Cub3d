#include "Cupid.h"

static void	draw_minimap_tile(t_cube *cube, int map_x, int map_y, int color)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = cube->minimap.position_x + map_x * cube->minimap.scale;
	start_y = cube->minimap.position_y + map_y * cube->minimap.scale;
	y = 0;
	while (y < cube->minimap.scale)
	{
		x = 0;
		while (x < cube->minimap.scale)
		{
			pixel_put(cube, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap_player(t_cube *cube)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < cube->minimap.size)
	{
		x = 0;
		while (x < cube->minimap.size)
		{
			pixel_put(cube, cube->minimap.center_x - cube->minimap.size / 2 + x,
				cube->minimap.center_y - cube->minimap.size / 2 + y, 0x7D460F);
			x++;
		}
		y++;
	}
	i = 0;
	while (i < cube->minimap.size + 4)
	{
		x = cube->minimap.center_x + (int)(cos(cube->player.h_angle) * i);
		y = cube->minimap.center_y + (int)(sin(cube->player.h_angle) * i);
		pixel_put(cube, x, y, 0x7D460F);
		i++;
	}
}

int	get_color(int map_x, int map_y, t_cube *cube)
{
	char	tile;

	if (map_y >= 0 && map_y < cube->map.length && map_x >= 0
		&& map_x < (int)ft_strlen(cube->map.map[map_y]))
	{
		tile = cube->map.map[map_y][map_x];
		if (tile == '1')
			return (0x444444);
		else if (tile == 'D')
			return (0x990000);
		else if (tile == 'O')
			return (0xFFA500);
		else if (ft_isin(tile, "0NSEW"))
			return (0xCCCCCC);
	}
	return (0x000000);
}

void	draw_minimap_border(t_cube *cube)
{
	int	x;
	int	y;
	int	size;
	int	color;

	size = cube->minimap.tile_count * cube->minimap.scale;
	color = 0xCCCCCC;
	x = 0;
	while (x < size)
	{
		pixel_put(cube, cube->minimap.position_x + x, cube->minimap.position_y,
			color);
		pixel_put(cube, cube->minimap.position_x + x, cube->minimap.position_y
			+ size - 1, color);
		x++;
	}
	y = 0;
	while (y < size)
	{
		pixel_put(cube, cube->minimap.position_x, cube->minimap.position_y + y,
			color);
		pixel_put(cube, cube->minimap.position_x + size - 1,
			cube->minimap.position_y + y, color);
		y++;
	}
}

void	render_minimap(t_cube *cube)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;
	int	color;

	cube->minimap.player_x = (int)(cube->player.x / TILE_SIZE);
	cube->minimap.player_y = (int)(cube->player.y / TILE_SIZE);
	y = -cube->minimap.radius;
	while (y <= cube->minimap.radius)
	{
		x = -cube->minimap.radius;
		while (x <= cube->minimap.radius)
		{
			map_x = cube->minimap.player_x + x;
			map_y = cube->minimap.player_y + y;
			color = get_color(map_x, map_y, cube);
			draw_minimap_tile(cube, x + cube->minimap.radius, y
				+ cube->minimap.radius, color);
			x++;
		}
		y++;
	}
	draw_minimap_border(cube);
	draw_minimap_player(cube);
}
