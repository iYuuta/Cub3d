#include "Cupid.h"

void draw_angles(t_cub *cub)
{
    char str[50];

    sprintf(str, "h_angle: %.2f", cub->player->h_angle);
    mlx_string_put(cub->mlx, cub->win, 10, 10, green, str);
    sprintf(str, "v_angle: %.2f", cub->player->v_angle);
    mlx_string_put(cub->mlx, cub->win, 10, 30, green, str);
}

void draw_line(t_cub *cub, int x, float dir)
{
    int y;
    float line_hight;
    float fix;
    int height;

    y = 0;
    height = cub->player->v_angle ;
    ray_casting(cub, dir);
    fix = fix_angle(cub->player->h_angle - dir);
    line_hight = (TILE_SIZE * HEIGHT) / (cub->ray->dist * cos(fix));
    while (y < (HEIGHT - line_hight) / 2)
        mlx_pixel_put(cub->mlx, cub->win, x, y++, white);
    if (line_hight > HEIGHT)
        line_hight = HEIGHT;
    while (line_hight-- > 0)
    {
        mlx_pixel_put(cub->mlx, cub->win, x, y, red);
        y++;
    }
    while (y < HEIGHT)
        mlx_pixel_put(cub->mlx, cub->win, x, y++, black);
}

void draw_view(t_cub *cub)
{
    int x;
    float dir;
    float fov;

    fov = 60 * (PI / 180);
    dir = cub->player->h_angle - (fov / 2);
    x = 0;
    while (x < WIDTH)
    {    
        draw_line(cub, x, dir);
        dir += fov / WIDTH;
        x++;
    }
    draw_angles(cub);
}