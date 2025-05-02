#ifndef CUPID_H
# define CUPID_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TITLE "Cube3d"
# define HEIGHT 600
# define WIDTH 600

# define ESC 53

# define CLOSE_BUTTON 17

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_data;

#endif