/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:59:59 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 17:58:46 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void			print_lines(t_list *lines);
void			print_identifiers(t_cube cube);
void			print_rgb(t_rgb rgb);
void			print_map(char **map);

static int	valid_map_name(char *str)
{
	int	i;

	if (!str || ft_strlen(str) < 4)
		return (0);
	i = ft_strlen(str) - 1;
	if (str[i--] == 'b' && str[i--] == 'u' && str[i--] == 'c' && str[i] == '.')
		return (1);
	return (0);
}

static t_list	*read_lines(char *str)
{
	char	*line;
	int		fd;
	t_list	*lines;

	lines = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Invalid file path or permisions");
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&lines, ft_lstnew(ft_strdup(line)));
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		ft_error("Failed to close the map file");
	return (lines);
}

void	parse(int argc, char **argv, t_cube *cube)
{
	if (argc != 2)
		ft_error("Invalid Argument: takes one argument");
	if (!valid_map_name(argv[1]))
		ft_error("Invalid file name: must end with .cub");
	cube->lines = read_lines(argv[1]);
	if (!cube->lines)
		ft_error("Empty Map File");
	init_elements(cube);
	init_rgb(cube->f, &cube->floor_rgb);
	init_rgb(cube->c, &cube->celling_rgb);
	init_map(cube);
	// print_identifiers(*cube);
	// print_rgb(cube->floor_rgb);
	// print_rgb(cube->celling_rgb);
	print_map(cube->map);
}
