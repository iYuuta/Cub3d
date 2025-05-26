#include "Cupid.h"

void move_player(t_cube *cub, float new_x, float new_y)
{
    int x;
    int y;
    int old_x;
    int old_y;

    x = (int)(new_x / TILE_SIZE);
    y = (int)(new_y / TILE_SIZE);
    old_x = (int)(cub->player.x / TILE_SIZE);
    old_y = (int)(cub->player.y / TILE_SIZE);
    if (y < 0 || y >= cub->map.length)
        return ;
    if (x < 0 || x >= (int)ft_strlen(cub->map.map[y]))
        return ;
    if (!ft_strchr("1 ", cub->map.map[old_y][x]))
        cub->player.x = new_x;
    if (!ft_strchr("1 ", cub->map.map[y][old_x]))
        cub->player.y = new_y;
    return ;
}

int check_angle(t_cube *cub)
{
    if (cub->key.up == 1 && cub->player.v_angle < 720)
        cub->player.v_angle += 8;
    if (cub->key.left == 1)
        cub->player.h_angle -= 0.04;
    if (cub->key.down == 1 && cub->player.v_angle > 0)
        cub->player.v_angle -= 8;
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

int	mouse_move(int x, int y, t_cube *cub)
{
    int delta_x;
    int delta_y;

    if (!cub->mouse_drag)
    {
        cub->mouse_prev_x = x;
        cub->mouse_prev_y = y;
        return (0);
    }

    delta_x = x - cub->mouse_prev_x;
    delta_y = y - cub->mouse_prev_y;
    cub->mouse_prev_x = x;
    cub->mouse_prev_y = y;
    cub->player.h_angle += delta_x * 0.01;
    cub->player.v_angle += delta_y * 0.5;
    if (cub->player.v_angle > 720)
        cub->player.v_angle = 720;
    if (cub->player.v_angle < 0)
        cub->player.v_angle = 0;
    detect_move(cub);
    return (0);
}

int mouse_press(int button, int x, int y, t_cube *cub)
{
    (void)x;
    (void)y;

    if (button == 1)
        cub->mouse_drag = 1;

    return (0);
}

int mouse_release(int button, int x, int y, t_cube *cub)
{
    (void)x;
    (void)y;

    if (button == 1)
        cub->mouse_drag = 0;

    return (0);
}

int player_movement(t_cube *cub)
{
    render(cub);
    mlx_hook(cub->win, 2, 1L << 0, pressed, cub);
    mlx_hook(cub->win, 3, 1L << 1, released, cub);
    mlx_hook(cub->win, 4, 1L << 2, mouse_press, cub);
    mlx_hook(cub->win, 5, 1L << 3, mouse_release, cub);
    mlx_hook(cub->win, 6, 1L << 6, mouse_move, cub);
    mlx_loop_hook(cub->mlx, detect_move, cub);
    mlx_loop(cub->mlx);
    return (0);
}
