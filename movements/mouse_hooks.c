#include "Cupid.h"

int	mouse_move(int x, int y, t_cube *cub)
{
	int	delta_x;
	int	delta_y;

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
	if (delta_y < 0 && cub->player.v_angle < 720)
		cub->player.v_angle += 6;
	else if (delta_y > 0 && cub->player.v_angle > 0)
		cub->player.v_angle -= 6;
	if (delta_x < 0)
		cub->player.h_angle -= 0.02;
	else if (delta_x > 0)
		cub->player.h_angle += 0.02;
	render(cub);
	return (0);
}

int	mouse_press(int button, int x, int y, t_cube *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->mouse_drag = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_cube *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->mouse_drag = 0;
	return (0);
}
