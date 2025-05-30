#include "Cupid.h"

void	move_player(t_cube *cub, float new_x, float new_y)
{
	int	x;
	int	y;
	int	old_x;
	int	old_y;

	x = (int)((cub->player.x + new_x * 10) / TILE_SIZE);
	y = (int)((cub->player.y + new_y * 10) / TILE_SIZE);
	old_x = (int)(cub->player.x / TILE_SIZE);
	old_y = (int)(cub->player.y / TILE_SIZE);
	if (y < 0 || y >= cub->map.length)
		return ;
	if (x < 0 || x >= (int)ft_strlen(cub->map.map[y]))
		return ;
	if (!ft_strchr("1 D", cub->map.map[y][x])
		&& !ft_strchr("1 D", cub->map.map[old_y][x])
		&& !ft_strchr("1 D", cub->map.map[y][old_x]))
	{
		cub->player.x += new_x * cub->key.speed;
		cub->player.y += new_y * cub->key.speed;
	}
	else if (!ft_strchr("1 D", cub->map.map[old_y][x]))
		cub->player.x += new_x * cub->key.speed;
	else if (!ft_strchr("1 D", cub->map.map[y][old_x]))
		cub->player.y += new_y * cub->key.speed;
	return ;
}

void	check_door(t_cube *cub)
{
	int	y;
	int	x;

	x = (cub->player.x / TILE_SIZE) + cos(cub->player.h_angle) * 1;
	y = (cub->player.y / TILE_SIZE) + sin(cub->player.h_angle) * 1;
	if (y < 0 || y >= cub->map.length)
		return ;
	if (x < 0 || x >= (int)ft_strlen(cub->map.map[y]))
		return ;
	cub->key.door_status += 1;
	if (cub->map.map[y][x] == 'D')
		cub->map.map[y][x] = 'O';
	else if (cub->map.map[y][x] == 'O')
		cub->map.map[y][x] = 'D';
}

void	check_move(t_cube *cub, float x, float y)
{
	if (cub->key.esc)
		close_window(cub);
	if (cub->key.door_status == 1)
		check_door(cub);
	if (cub->key.w == 1)
		move_player(cub, x, y);
	if (cub->key.s == 1)
		move_player(cub, -x, -y);
	if (cub->key.d == 1)
		move_player(cub, -y, x);
	if (cub->key.a == 1)
		move_player(cub, y, -x);
}

int	detect_move(void *ptr)
{
	t_cube	*cub;
	float	x;
	float	y;

	cub = (t_cube *)ptr;
	cub->key.speed = 4;
	if ((cub->key.w == 1 || cub->key.s == 1)
		&& (cub->key.a == 1 || cub->key.d == 1))
		cub->key.speed = 2;
	x = cos(cub->player.h_angle);
	y = sin(cub->player.h_angle);
	check_angle(cub);
	check_move(cub, x, y);
	if (current_time() - cub->sprite_timer > 90)
	{
		cub->sprite_timer = current_time();
		change_sprite(cub);
	}
	render(cub);
	return (0);
}

int	player_movement(t_cube *cub)
{
	render(cub);
	mlx_hook(cub->win, 2, 1L << 0, pressed, cub);
	mlx_hook(cub->win, 3, 1L << 1, released, cub);
	mlx_hook(cub->win, 4, 1L << 2, mouse_press, cub);
	mlx_hook(cub->win, 5, 1L << 3, mouse_release, cub);
	mlx_hook(cub->win, 6, 1L << 6, mouse_move, cub);
	mlx_hook(cub->win, CLOSE_BUTTON, 0, close_window, cub);
	mlx_loop_hook(cub->mlx, detect_move, cub);
	mlx_loop(cub->mlx);
	return (0);
}
