#include "Cupid.h"

int is_move_valid(t_map *map, float tile_x, float tile_y)
{
    int x;
    int y;

    x = (int)(tile_x / TILE_SIZE);
    y = (int)(tile_y / TILE_SIZE);
    if (y < 0 || y >= map->length)
        return (0);
    if (x < 0 || x >= (int)ft_strlen(map->map[y]))
        return (0);
    if (ft_strchr("1 ", map->map[y][x]))
        return (0);
    return (1);
}

int move_player(t_cube *cub, float new_x, float new_y)
{
    if (!is_move_valid(&(cub->map), new_x, new_y))
        return (0);
    cub->player.x = new_x;
    cub->player.y = new_y;
    return (1);
}

int check_angle(t_cube *cub)
{
    // if (cub->key.up == 1 && cub->player.v_angle > ((PI / 4) * -1))
    //     cub->player.v_angle -= 0.04;
    if (cub->key.left == 1)
        cub->player.h_angle -= 0.04;
    // if (cub->key.down == 1 && cub->player.v_angle < (PI / 4))
    //     cub->player.v_angle += 0.04;
    if (cub->key.right == 1)
        cub->player.h_angle += 0.04;
    if (cub->player.h_angle < 0 || cub->player.h_angle > 2 * PI)
        cub->player.h_angle = fix_angle(cub->player.h_angle);
    return (1);
}

int detect_move(void *ptr)
{
    t_cube *cub;
    float x;
    float y;

    cub = (t_cube *)ptr;
    cub->key.speed = 4;
    if ((cub->key.w == 1 || cub->key.s == 1) && (cub->key.a == 1 || cub->key.d == 1))
        cub->key.speed = 2;
    x = cos(cub->player.h_angle) * cub->key.speed;
    y = sin(cub->player.h_angle) * cub->key.speed;
    check_angle(cub);
    if (cub->key.esc)
        close_window(cub);
    if (cub->key.w == 1)
        move_player(cub, cub->player.x + x, cub->player.y + y);
    if (cub->key.s == 1)
        move_player(cub, cub->player.x - x, cub->player.y - y);
    if (cub->key.d == 1)
        move_player(cub, cub->player.x - y, cub->player.y + x);
    if (cub->key.a == 1)
        move_player(cub, cub->player.x + y, cub->player.y - x);
    render(cub);
    return (0);
}

int player_movement(t_cube *cub)
{
    render(cub);
    mlx_hook(cub->win, 2, 1L << 0, pressed, cub);
    mlx_hook(cub->win, 3, 1L << 1, released, cub);
    mlx_loop_hook(cub->mlx, detect_move, cub);
    mlx_loop(cub->mlx);
    return (0);
}
