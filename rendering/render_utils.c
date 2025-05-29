#include "Cupid.h"

float	fix_angle(float angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

int	get_pixel_color(t_texture texture, int x, int y)
{
	int	offset;

	x %= TILE_SIZE;
	y %= TILE_SIZE;
	if (x < 0 || x >= TILE_SIZE || y < 0 || y >= TILE_SIZE)
		return (0);
	offset = y * texture.size_line + x * (texture.bits_per_pixel / 8);
	return (*(int *)(texture.addr + offset));
}

void	pixel_put(t_cube *cub, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = y * cub->image.size_line + x * (cub->image.bits_per_pixel / 8);
	*(int *)(cub->image.addr + offset) = color;
}

void	get_texture_position(t_cube *cub, float wall_x)
{
	wall_x = fmod(wall_x, TILE_SIZE);
	if (wall_x < 0)
		wall_x += TILE_SIZE;
	cub->column.tex_x = (int)(wall_x * (64 / (float)TILE_SIZE));
}
