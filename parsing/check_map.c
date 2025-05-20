/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:59:59 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 03:19:42 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void			print_map(t_list *lines);
void			print_identifiers(t_map map);
void			print_rgb(t_rgb rgb);

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

static t_list	*read_map(char *str)
{
	char	*line;
	int		fd;
	t_list	*map;

	map = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Invalid map file path or permisions");
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
		ft_error("Failed to close the map");
	return (map);
}

void	check_map(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		ft_error("Invalid Argument: takes one argument");
	if (!valid_map_name(argv[1]))
		ft_error("Invalid map name: must end with .cub");
	data->map.lines = read_map(argv[1]);
	if (!data->map.lines)
		ft_error("Empty map");
	init_elements(&data->map);
	print_map(data->map.lines);
	print_identifiers(data->map);
	print_rgb(data->map.floor_rgb);
	print_rgb(data->map.celling_rgb);
}

// check later ? for the valid charaters in the map