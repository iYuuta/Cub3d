/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cupid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:00:16 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/17 18:50:58 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUPID_H
# define CUPID_H

# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
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

typedef struct s_map
{
	t_list			*list;
}					t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	struct s_map	map;
}					t_data;

// parsing
void				check_map(int argc, char **argv, t_data *data);

// rendering
int					close_window(t_data *data);
int					key_hook(int keycode, t_data *data);

// utils
void				ft_error(char *message);
void				ft_exit(void *value);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_putendl_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*get_next_line(int fd);

#endif
