#include "Cupid.h"

void	pixel_put(t_texture *texture, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x > texture->width || y < 0 || y > texture->height)
		return ;
	offset = y * texture->size_line + x * (texture->bits_per_pixel / 8);
	*(int *)(texture->addr + offset) = color;
}

void draw_line(t_cube *cub, int x, float dir)
{
    int y;
    float line_hight;
    float fix;

    y = 0;
    ray_casting(cub, dir);
    fix = fix_angle(cub->player.h_angle - dir);
    line_hight = (TILE_SIZE * HEIGHT) / (cub->ray.dist * cos(fix));
    while (y < (HEIGHT - line_hight) / 2)
        mlx_pixel_put(cub->mlx, cub->win, x, y++, cub->celling);
    if (line_hight > HEIGHT)
        line_hight = HEIGHT;
    while (line_hight-- > 0)
    {
        mlx_pixel_put(cub->mlx, cub->win, x, y, RED);
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