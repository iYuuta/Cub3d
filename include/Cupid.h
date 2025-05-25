#ifndef CUPID_H
# define CUPID_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdio.h> // to remove later
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TITLE "cub3D"
# define HEIGHT 720
# define WIDTH 1280

# define ESC 65307

# define CLOSE_BUTTON 17

# define W 119
# define D 100
# define S 115
# define A 97

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define TILE_SIZE 64
# define PI 3.1415929
# define FOV 1.047197633


# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;

}					t_list;

typedef struct s_gc
{
	void			*ptr;
	struct s_gc		*next;

}					t_gc;

typedef struct s_texture
{
	void			*texture;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*name;
	int				height;
	int				width;

}					t_texture;

typedef struct s_map
{
	char			**map;
	int				length;
}					t_map;

typedef struct s_column
{
	float			tex_pos;
	int				tex_y;
	int				wall;
	int				start;
	int				end;
	float			pixel_step;
}					t_column;

typedef struct s_ray
{
	int				side;
	float			dist;
	int				curr_x;
	int				curr_y;
	float			x_step;
	float			y_step;
	float			y_dir;
	float			x_dir;
	float			x_dist;
	float			y_dist;
	float			x_side_dis;
	float			y_side_dis;
}					t_ray;

typedef struct s_key
{
	int				speed;
	int				esc;
	int				w;
	int				d;
	int				s;
	int				a;
	int				up;
	int				down;
	int				right;
	int				left;
}					t_key;

typedef struct s_player
{
	float			y;
	float			x;
	float			h_angle;
	float			v_angle;
}					t_player;

typedef struct s_cube
{
	void			*mlx;
	void			*win;

	t_list			*lines;
	t_texture		image;
	char			*f;
	char			*c;

	t_ray			ray;
	t_column		column;
	t_map			map;
	t_key			key;
	t_player		player;

	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;

	unsigned int	floor;
	unsigned int	celling;

}					t_cube;

// parsing
void				init_rgb(char *str, unsigned int *rgb);
void				init_map(t_cube *cube);
void				check_map(char **map);
void				check_player(char **map);
void				init_elements(t_cube *cube);
void				parse(int argc, char **argv, t_cube *cube);
void				init_data(t_cube *cube);
// rendering

void				render(t_cube *cube);
float				fix_angle(float angle);
void				ray_casting(t_cube *cube, float new_angle);
int					detect_move(void *ptr);
int					close_window(t_cube *cube);
int					player_movement(t_cube *cub);
int					pressed(int key, void *ptr);
int					released(int key, void *ptr);
// utils
unsigned long long	ft_atol(const char *str);
void				ft_error(char *message);
void				ft_exit(int exit_status);
void				ft_free(void);
t_gc				**ft_gc(void);
int					ft_isdigit(char c);
int					ft_isallspace(char *str);
int					ft_isin(const char c, const char *charset);
int					ft_isspace(char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				*ft_malloc(size_t size);
t_list				*ft_lstlast(t_list *lst);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(const char *s, int fd);
char				**ft_free_split(char **arr, int i);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strspn(const char *s, const char *accept);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strcspn(const char *s, const char *reject);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*get_next_line(int fd);

#endif
