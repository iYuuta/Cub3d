#include "Cupid.h"

float fix_angle(float angle)
{
    angle = fmod(angle, 2 * PI);
    if (angle < 0)
        angle += 2 * PI;
    return angle;
}

int get_pixel_color(t_texture texture, int x, int y)
{
	int offset;

	x %= 64;
	y %= 64;
	if (x < 0 || x >= 64 || y < 0 || y >= 64)
		return (0);
	offset = y * texture.size_line + x * (texture.bits_per_pixel / 8);
	return (*(int *)(texture.addr + offset));
}

void	pixel_put(t_cube *cub, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	offset = y * cub->image.size_line + x * (cub->image.bits_per_pixel / 8);
	*(int *)(cub->image.addr + offset) = color;
}

void draw_pixel(t_cube *cub, int x, int y)
{
    int color;

    if (cub->column.wall == NORTH)
       color = get_pixel_color(cub->no, cub->column.tex_pos, y);
    else if (cub->column.wall == SOUTH)
       color = get_pixel_color(cub->so, cub->column.tex_pos, y);
    else if (cub->column.wall == EAST)
       color = get_pixel_color(cub->ea, cub->column.tex_pos, y);
    else
       color = get_pixel_color(cub->we, cub->column.tex_pos, y);
    pixel_put(cub, x, y, color);
}

void calculate_column_info(t_cube *cub, float dir)
{
    float	projection_fix;

    ray_casting(cub, dir);
    projection_fix = (WIDTH / 2) / tan(FOV / 2);
    cub->column.length = (TILE_SIZE * projection_fix)
    / (cub->ray.dist * cos(fix_angle(cub->player.h_angle - dir)));
    cub->column.start = cub->player.v_angle - (cub->column.length / 2);
    cub->column.end = cub->column.start + cub->column.length;
    if (cub->column.start < 0)
        cub->column.start = 0;
    if (cub->column.end > HEIGHT)
        cub->column.end = HEIGHT;
}

void draw_line(t_cube *cub, int x, float dir)
{
    int		y;

    y = 0;
    ray_casting(cub, dir);
    calculate_column_info(cub, dir);
    while (y < cub->column.start)
        pixel_put(cub, x, y++, cub->celling);
    while (y < cub->column.end)
    {
        draw_pixel(cub, x, y);
        y++;
    }
    while (y < HEIGHT)
        pixel_put(cub, x, y++, cub->floor);
}

void render(t_cube *cub)
{
    int x;
    float dir;
    float fov;
    fov = 60 * (PI / 180);
    dir = cub->player.h_angle - (fov / 2);
    cub->image.texture = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
    if (!cub->image.texture)
        exit(1); //free sum stuff
    cub->image.addr = mlx_get_data_addr(cub->image.texture,
        &(cub->image.bits_per_pixel), &(cub->image.size_line), &(cub->image.endian));
    if (!cub->image.addr)
        exit(1); //free sum stuff
    x = 0;
    while (x < WIDTH)
    {    
        draw_line(cub, x, dir);
        dir += fov / WIDTH;
        x++;
    }
    mlx_put_image_to_window(cub->mlx, cub->win, cub->image.texture, 0, 0);
    mlx_destroy_image(cub->mlx, cub->image.texture);
}
