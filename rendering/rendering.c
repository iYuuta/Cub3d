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

void	calculate_column_info(t_cube *cub, float dir)
{
	float	projection_fix;

	projection_fix = (WIDTH / 2) / tan(FOV / 2);
	cub->column.length = (TILE_SIZE * projection_fix)
		/ (cub->ray.dist * cos(fix_angle(cub->player.h_angle - dir)));
	cub->column.start = cub->player.v_angle - (cub->column.length / 2);
	cub->column.end = cub->column.start + cub->column.length;
	cub->column.tex_y = 0;
	if (cub->column.start < 0)
	{
		cub->column.tex_y = (-cub->column.start) * cub->column.pixel_step;
		cub->column.start = 0;
	}
	if (cub->column.end > HEIGHT)
		cub->column.end = HEIGHT;
	cub->column.pixel_step = (float)64 / cub->column.length;
}

void	draw_pixel(t_cube *cub, int x, int y, int tex_y)
{
	int	color;

	if (cub->column.wall == NORTH)
		color = get_pixel_color(cub->no, cub->column.tex_x, tex_y);
	else if (cub->column.wall == SOUTH)
		color = get_pixel_color(cub->so, cub->column.tex_x, tex_y);
	else if (cub->column.wall == EAST)
		color = get_pixel_color(cub->ea, cub->column.tex_x, tex_y);
	else if (cub->column.wall == WEST)
		color = get_pixel_color(cub->we, cub->column.tex_x, tex_y);
	else if (cub->column.wall == DOOR)
		color = get_pixel_color(cub->door[cub->curr_door], cub->column.tex_x, tex_y);
	pixel_put(cub, x, y, color);
}

void	draw_line(t_cube *cub, int x, float dir)
{
	int	y;
	int	tex_y;

	y = 0;
	ray_casting(cub, dir);
	calculate_column_info(cub, dir);
	while (y < cub->column.start)
		pixel_put(cub, x, y++, cub->ceiling);
	while (y < cub->column.end)
	{
		tex_y = (int)cub->column.tex_y;
		draw_pixel(cub, x, y, tex_y);
		cub->column.tex_y += cub->column.pixel_step;
		y++;
	}
	while (y < HEIGHT)
		pixel_put(cub, x, y++, cub->floor);
}

void	render(t_cube *cub)
{
	int		x;
	float	dir;

	dir = cub->player.h_angle - (FOV / 2);
	x = 0;
	while (x < WIDTH)
	{
		draw_line(cub, x, dir);
		dir += FOV / WIDTH;
		x++;
	}
	render_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->image.texture, 0, 0);
}
