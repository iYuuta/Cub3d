#ifndef CUPID_H
# define CUPID_H

# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WIDTH 1300
# define HEIGHT 700
# define black 0x000000
# define white 0xFFFFFF
# define red 0xFF0000
# define green 0x00FF00
# define blue 0x0000FF
# define TITLE "cub3D"
# define TILE_SIZE 64
# define TILE_SIZE 64
# define OPEN_MAX 1024
# define CLOSE_BUTTON 17
# define ESC 65307
# define W 119
# define D 100
# define S 115
# define A 97
# define up 65362
# define down 65364
# define right 65363
# define left 65361
# define PI 3.1415929
# define FOV (PI / 3)

typedef enum e_orientation
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}						t_orientation;

typedef struct s_map
{
	char				**map;
	int					length;
	int					orientation;
}						t_map;

typedef struct s_textures
{
	void				*texture1;
	void				*texture2;
	void				*texture3;
	void				*texture4;
	void				*texture5;
	void				*texture6;
	void				*texture7;
}						t_textures;

typedef struct s_player
{
	float	y;
	float	x;
	float	h_angle;
	float	v_angle;
}			t_player;

typedef struct s_ray
{
	int		side;
	float	dist;
	int		curr_x;
	int		curr_y;
	float	x_step;
	float	y_step;
	float	y_dir;
	float	x_dir;
	float	x_dist;
	float	y_dist;
	float	x_side_dis;
    float	y_side_dis;
}			t_ray;

typedef struct s_cub
{
	void				*mlx;
	void				*win;
	struct s_map		*map;
	struct s_ray		*ray;
	struct s_player		*player;
	struct s_textures	*textures;
}						t_cub;

/*************************** utils ***************************/
void					ft_putendl_fd(char *s, int fd);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_substr(char const *s, unsigned int start, size_t len);
char					*get_next_line(int fd);

/************************* movements *************************/
t_cub *create_map(void);
int player_movement(t_cub *cub);
float fix_angle(float angle);

/************************ rendering **************************/
void ray_casting(t_cub *cub, float new_angle);
void draw_view(t_cub *cub);

#endif
