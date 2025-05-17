#ifndef CUPID_H
# define CUPID_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TITLE "Cube3D"

# define ESC 53

# define CLOSE_BUTTON 17

typedef enum e_orientation
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}		t_orientation;

typedef struct s_map
{
	char 			**map;
	int 			length;
	int 			width;
	int 			player_position;
	int 			orientation;
	unsigned int	floor;
	unsigned int	ceiling;
}		t_map;

typedef struct s_textures
{
	void *north_wall;
	void *east_wall;
	void *south_wall;
	void *west_wall;
	void *texture5;
	void *texture6;
	void *texture7;
}		t_textures;

typedef struct s_cub
{
	void				*mlx;
	void				*win;
	struct s_map		*map;
	struct s_textures	*textures;
}			t_cub;

void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif