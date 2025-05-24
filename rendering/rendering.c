#include "Cupid.h"

void	pixel_put(t_texture *texture, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x > texture->width || y < 0 || y > texture->height)
		return ;
	offset = y * texture->size_line + x * (texture->bits_per_pixel / 8);
	*(int *)(texture->addr + offset) = color;
}

int	get_pixel(t_texture texture, int x, int y)
{
	int	offset;

	x = x % 64;
	y = y % 64;
	if (x < 0 || x > texture.width || y < 0 || y > texture.height)
		return (0);
	offset = y * texture.size_line + x * (texture.bits_per_pixel / 8);
	return (*(int *)(texture.addr + offset));
}

void draw_line(t_cube *cub, int x, float dir)
{
    int y;
    float line_height;
    float fix;

    y = 0;
    ray_casting(cub, dir);
    fix = fix_angle(cub->player.h_angle - dir);
    line_height = (TILE_SIZE * HEIGHT) / (cub->ray.dist * cos(fix));
    while (y < (HEIGHT - line_height) / 2)
        mlx_pixel_put(cub->mlx, cub->win, x, y++, cub->celling);
    if (line_height > HEIGHT)
        line_height = HEIGHT;
    while (line_height-- > 0)
    {
        mlx_pixel_put(cub->mlx, cub->win, x, y, get_pixel(cub->no, x, ((y - (HEIGHT / 2.0f) - (line_height / 2.0f)) / (line_height)) * cub->no.height));
        y++;
    }
    while (y < HEIGHT)
        mlx_pixel_put(cub->mlx, cub->win, x, y++, cub->floor);
}

void render(t_cube *cub)
{
    int x;
    float dir;
    float fov;

    fov = 60 * (PI / 180);
    dir = cub->player.h_angle - (fov / 2);
    x = 0;
    while (x < WIDTH)
    {    
        draw_line(cub, x, dir);
        dir += fov / WIDTH;
        x++;
    }
}