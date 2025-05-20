/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cupid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:00:16 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 15:37:00 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUPID_H
# define CUPID_H

# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdio.h> // to remove later
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TITLE "cub3D"
# define HEIGHT 600
# define WIDTH 600

# define ESC 65307

# define CLOSE_BUTTON 17

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;

}					t_list;

typedef struct s_rgb
{
	int			red;
	int			green;
	int			blue;
}					t_rgb;

typedef struct s_map
{
	t_list			*lines;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	char			**maze;
	t_rgb			floor_rgb;
	t_rgb			celling_rgb;
}					t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_map			map;
}					t_data;

// parsing
void				init_rgb(char *str, t_rgb *rgb);
void				init_elements(t_map *map);
void				check_map(int argc, char **argv, t_data *data);

// rendering
int					close_window(t_data *data);
int					key_hook(int keycode, t_data *data);

// utils
unsigned long long	ft_atol(const char *str);
void				ft_error(char *message);
void				ft_exit(void *value);
int					ft_isdigit(char c);
int					ft_isallspace(char *str);
int					ft_isin(const char c, const char *charset);
int					ft_isspace(char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);
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
