#include "Cupid.h"

static void	draw_minimap_tile(t_cube *cub, int map_x, int map_y, int color)
{
	int	x;
	int	y;
	int start_x;
	int start_y;

	start_x = MINIMAP_START_X + map_x * MINIMAP_SCALE;
	start_y = MINIMAP_START_Y + map_y * MINIMAP_SCALE;
	y = 0;
	while (y < MINIMAP_SCALE)
	{
		x = 0;
		while (x < MINIMAP_SCALE)
		{
			pixel_put(cub, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap_player(t_cube *cub)
{
	int	x;
	int	y;
	int	i;
	int	player_x;
	int	player_y;

	player_x = MINIMAP_START_X + (int)(cub->player.x / TILE_SIZE * MINIMAP_SCALE);
	player_y = MINIMAP_START_Y + (int)(cub->player.y / TILE_SIZE * MINIMAP_SCALE);
	pixel_put(cub, player_x, player_y, 0xE60000);
	pixel_put(cub, player_x + 1, player_y, 0xE60000);
	pixel_put(cub, player_x, player_y + 1, 0xE60000);
	pixel_put(cub, player_x + 1, player_y + 1, 0xE60000);
	i = 0;
	while (i < 5)
	{
		x = player_x + (int)(cos(cub->player.h_angle) * i);
		y = player_y + (int)(sin(cub->player.h_angle) * i);
		pixel_put(cub, x, y, 0xFF0000);
		i++;
	}
}

void	render_minimap(t_cube *cub)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < cub->map.length)
	{
		x = 0;
		while (x < (int)ft_strlen(cub->map.map[y]))
		{
			tile = cub->map.map[y][x];
			if (tile == '1')
				draw_minimap_tile(cub, x, y, 0x444444);
			else if (tile == 'D' || tile == 'O')
				draw_minimap_tile(cub, x, y, 0xFFA500);
			else if (tile == '0')
				draw_minimap_tile(cub, x, y, 0xCCCCCC);
			x++;
		}
		y++;
	}
	draw_minimap_player(cub);
}
