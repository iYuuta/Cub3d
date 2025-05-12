#ifndef CUPID_H
# define CUPID_H

# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TITLE "cub3D"

# define ESC 53

# define CLOSE_BUTTON 17

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
	int					player_position;
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

typedef struct s_cub
{
	void				*mlx;
	void				*win;
	struct s_map		*map;
	struct s_textures	*textures;
}						t_cub;

void					ft_putendl_fd(char *s, int fd);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_substr(char const *s, unsigned int start, size_t len);
char					*get_next_line(int fd);

#endif
