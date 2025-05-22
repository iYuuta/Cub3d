#include "Cupid.h"

int is_move_valid(t_map *map, float tile_x, float tile_y)
{
    int x;
    int y;

    x = (int)(tile_x / TILE_SIZE);
    y = (int)(tile_y / TILE_SIZE);
    if (y < 0 || y >= map->length)
        return (0);
    if (x < 0 || x >= ft_strlen(map->map[y]))
        return (0);
    if (ft_strchr("1 ", map->map[y][x]))
        return (0);
    return (1);
}

int move_player(t_cub *cub, float new_x, float new_y)
{
    if (!is_move_valid(cub->map, new_x, new_y))
        return (0);
    cub->player->x = new_x;
    cub->player->y = new_y;
    return (1);
}

float fix_angle(float angle)
{
    angle = fmod(angle, PI * 2);
    if (angle < 0)
        angle += PI * 2;
    return (angle);
}

int check_angle(t_cub *cub, int move)
{
    if (move == up && cub->player->v_angle > ((PI / 4) * -1))
        cub->player->v_angle -= 0.08;
    else if (move == left)
        cub->player->h_angle -= 0.08;
    else if (move == down && cub->player->v_angle < (PI / 4))
        cub->player->v_angle += 0.08;
    else if (move == right)
        cub->player->h_angle += 0.08;
    else
        return (0);
    if (cub->player->h_angle <= (2 * PI) * -1 || cub->player->h_angle >= 2 * PI)
        cub->player->h_angle = fix_angle(cub->player->h_angle);
    return (1);
}

int detect_move(int move, void *ptr)
{
    t_cub *cub;
    float x;
    float y;

    cub = (t_cub *)ptr;
    if (move == ESC)
        exit(0);
    x = cos(cub->player->h_angle) * 8;
    y = sin(cub->player->h_angle) * 8;
    if (check_angle(cub, move))
        return (draw_view(cub), 0);
    if (move == W)
        move_player(cub, cub->player->x + x, cub->player->y + y);
    if (move == S)
        move_player(cub, cub->player->x - x, cub->player->y - y);
    if (move == D)
        move_player(cub, cub->player->x - y, cub->player->y + x);
    if (move == A)
        move_player(cub, cub->player->x + y, cub->player->y - x);
    draw_view(cub);
    return (0);
}

int player_movement(t_cub *cub)
{
    draw_view(cub);
    mlx_hook(cub->win, 2, 1L << 0, detect_move, cub);
    mlx_loop(cub->mlx);
    return (0);
}
