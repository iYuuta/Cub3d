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

void draw_pixel(t_cube *cub, int x, int y, int texture_y)
{
    int color;

    if (cub->column.wall == NORTH)
        color = get_pixel_color(cub->no, cub->column.tex_pos, texture_y);
    else if (cub->column.wall == SOUTH)
        color = get_pixel_color(cub->so, cub->column.tex_pos, texture_y);
    else if (cub->column.wall == EAST)
        color = get_pixel_color(cub->ea, cub->column.tex_pos, texture_y);
    else
        color = get_pixel_color(cub->we, cub->column.tex_pos, texture_y);
    pixel_put(cub, x, y, color);
}

void draw_line(t_cube *cub, int x, float dir)
{
    int y;
    int offset;
    float line_height;
    float projection_fix;
    float wall_top;
    float wall_bottom;
    float tex_step;
    float tex_pos;
    int texture_y;

    ray_casting(cub, dir);

    projection_fix = (WIDTH / 2) / tan(FOV / 2);
    line_height = (TILE_SIZE * projection_fix) / 
                  (cub->ray.dist * cos(fix_angle(cub->player.h_angle - dir)));

    if (line_height > HEIGHT)
        line_height = HEIGHT;

    offset = (HEIGHT / 2) - (cub->player.v_angle * (HEIGHT / 2));
    wall_top = offset - line_height / 2;
    wall_bottom = wall_top + line_height;

    // Ceiling
    y = 0;
    while (y < wall_top)
        pixel_put(cub, x, y++, cub->celling);

    // Texture stepping
    tex_step = (float)64 / line_height;
    tex_pos = 0;
    if (wall_top < 0) {
        tex_pos = -wall_top * tex_step;
        wall_top = 0;
    }

    // Wall
    while (y < wall_bottom && y < HEIGHT) {
        texture_y = (int)tex_pos & (64 - 1);
        draw_pixel(cub, x, y, texture_y);
        tex_pos += tex_step;
        y++;
    }

    // Floor
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
