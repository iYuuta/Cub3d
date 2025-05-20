/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:32:30 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 01:40:25 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

static char	*get_value(char *str)
{
	if (*str && !ft_isspace(*str))
		return (ft_error("Need space between element and value"), NULL);
	while (*str && ft_isspace(*str))
		str++;
	printf("%s\n", str);
	return (ft_strdup(str));
}

static void	add_element(char *str, t_map *map)
{
	static int	duplicates[6];
	int			i;

	while (*str && ft_isspace(*str))
		str++;
	if (!ft_strncmp(str, "NO", 2))
		(1) && (duplicates[0]++, str += 2, map->no = get_value(str));
	else if (!ft_strncmp(str, "SO", 2))
		(1) && (duplicates[1]++, str += 2, map->so = get_value(str));
	else if (!ft_strncmp(str, "WE", 2))
		(1) && (duplicates[2]++, str += 2, map->we = get_value(str));
	else if (!ft_strncmp(str, "EA", 2))
		(1) && (duplicates[3]++, str += 2, map->ea = get_value(str));
	else if (!ft_strncmp(str, "F", 1))
		(1) && (duplicates[4]++, str++, map->f = get_value(str));
	else if (!ft_strncmp(str, "C", 1))
		(1) && (duplicates[5]++, str++, map->c = get_value(str));
	i = 0;
	while (i < 6)
	{
		if (duplicates[i] > 1)
			ft_error("Duplicate Element");
		i++;
	}
}

void	init_elements(t_map *map)
{
	t_list	*current;
	char	*line;

	if (!map->lines)
		return ;
	current = map->lines;
	while (current)
	{
		line = current->content;
		add_element(line, map);
		current = current->next;
	}
}
