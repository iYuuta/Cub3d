/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:32:30 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 02:06:04 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

// free the elements of the map

static char	*get_value(char *str)
{
	if (*str && !ft_isspace(*str))
		return (ft_error("Need space between element and value"), NULL);
	while (*str && ft_isspace(*str))
		str++;
	if (!*str)
		return (ft_error("Empty element value"), NULL);
	return (ft_strdup(str));
}

static void	add_element(char *str, t_map *map)
{
	static int	dup[6];

	if (dup[0] > 1 || dup[1] > 1 || dup[2] > 1
		|| dup[3] > 1 || dup[4] > 1 || dup[5] > 1)
		ft_error("Duplicate Element");
	if (!ft_strncmp(str, "NO", 2))
		(1) && (dup[0]++, str += 2, map->no = get_value(str));
	else if (!ft_strncmp(str, "SO", 2))
		(1) && (dup[1]++, str += 2, map->so = get_value(str));
	else if (!ft_strncmp(str, "WE", 2))
		(1) && (dup[2]++, str += 2, map->we = get_value(str));
	else if (!ft_strncmp(str, "EA", 2))
		(1) && (dup[3]++, str += 2, map->ea = get_value(str));
	else if (!ft_strncmp(str, "F", 1))
		(1) && (dup[4]++, str++, map->f = get_value(str));
	else if (!ft_strncmp(str, "C", 1))
		(1) && (dup[5]++, str++, map->c = get_value(str));
	else if (*str && !ft_isin(*str, "01"))
		ft_error("Invalid Element");
}

static void	init_identifiers(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
}

void	init_elements(t_map *map)
{
	t_list	*current;
	char	*line;

	if (!map->lines)
		return ;
	init_identifiers(map);
	current = map->lines;
	while (current)
	{
		line = current->content;
		while (*line && ft_isspace(*line))
			line++;
		add_element(line, map);
		current = current->next;
	}
	if (!map->no || !map->so || !map->we || !map->ea || !map->f || !map->c)
		ft_error("Missing element");
}
