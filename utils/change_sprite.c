#include "Cupid.h"

long    current_time(void)
{
        struct timeval  tv;

        gettimeofday(&tv, NULL);
        return (((long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void change_sprite(t_cube *cube)
{
    static int counter;
    char *path;

    if (counter == 0)
        path = "textures/door_0.xpm";
    else if (counter == 1)
        path = "textures/door_1.xpm";
    else if (counter == 2)
        path = "textures/door_2.xpm";
    else if (counter == 3)
        path = "textures/door_3.xpm";
    else if (counter == 4)
    {
        path = "textures/door_4.xpm";
        counter = -1;
    }
    counter++;
	cube->door.texture = mlx_xpm_file_to_image(cube->mlx, path,
			&cube->door.height, &cube->door.width);
	if (!cube->door.texture)
		ft_error("Failed to load the door texture file");
	cube->door.addr = mlx_get_data_addr(cube->door.texture,
			&cube->door.bits_per_pixel,
			&cube->door.size_line,
			&cube->door.endian);
}
