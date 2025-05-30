#include "Cupid.h"

void	change_sprite(t_cube *cube)
{
	static int	counter;

	cube->curr_door = counter;
	if (counter == 10)
		counter = -1;
	counter++;
}

void	init_sprites(t_cube *cube)
{
	int		i;
	char	*name;

	i = 0;
	while (i < 11)
	{
		name = ft_strjoin("textures/fog/", ft_itoa(i + 1));
		if (!name)
			ft_error("Failed to find door texture file", cube);
		name = ft_strjoin(name, ".xpm");
		if (!name)
			ft_error("Failed to find door texture file", cube);
		cube->door[i].texture = mlx_xpm_file_to_image(cube->mlx, name,
				&(cube->door[i].width), &(cube->door[i].height));
		if (!cube->door[i].texture)
			ft_error("Failed to load the door texture file", cube);
		cube->door[i].addr = mlx_get_data_addr(cube->door[i].texture,
				&(cube->door[i].bits_per_pixel), &(cube->door[i].size_line),
				&(cube->door[i].endian));
		if (!cube->door[i].addr)
			ft_error("Failed to load the door texture file", cube);
		i++;
	}
	change_sprite(cube);
}

long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
