#include "Cupid.h"


void    init_sprites(t_cube *cube)
{
    int	i;
	char 		*name;

	i = 0;
	while (i < 11)
	{
		name = ft_strjoin("textures/fog/", ft_itoa(i + 1));
		if (!name)
			exit(5);
		name = ft_strjoin(name, ".xpm");
		if (!name)
			exit(5);
		cube->door[i].texture = mlx_xpm_file_to_image(cube->mlx, name, &(cube->door[i].width), &(cube->door[i].height));
		if (!cube->door[i].texture)
			ft_exit(EXIT_FAILURE);
		cube->door[i].addr =  mlx_get_data_addr(cube->door[i].texture,
        &(cube->door[i].bits_per_pixel), &(cube->door[i].size_line), &(cube->door[i].endian));
    	if (!cube->door[i].addr)
        	ft_exit(EXIT_FAILURE);
		i++;
	}
}

long    current_time(void)
{
        struct timeval  tv;

        gettimeofday(&tv, NULL);
        return (((long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void change_sprite(t_cube *cube)
{
    static int counter;

    cube->curr_door = &(cube->door[counter]);
    if (counter == 10)
        counter = -1;
    counter++;
}
