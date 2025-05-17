/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:59:59 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/17 16:11:39 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"
#include <string.h>

int	check_existence(t_map *map, int j, int i)
{
	if (j == 0 || j + 1 == map->length)
		return (1);
	if (i >= strlen(map->map[j - 1]) || i >= strlen(map->map[j + 1]))
		return (1);
	return (0);
}

int	check_surroundings(char **str, int i, int j)
{
	int	track;

	track = 0;
	if (str[j][i + 1] == ' ')
		return (1);
	if (str[j][i - 1] == ' ')
		return (1);
	if (str[j + 1][i] == ' ')
		return (1);
	if (str[j - 1][i] == ' ')
		return (1);
	return (0);
}

int	check_borders(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	j = -1;
	while (map->map[++j])
	{
		i = -1;
		while (map->map[j][++i])
		{
			if (!strchr("10 ", map->map[j][i]))
				return (1);
			if (check_existence(map, j, i) && (map->map[j][i] != '1'
					&& map->map[j][i] != ' '))
				return (1);
			else if ((map->map[j][i] != '1' && map->map[j][i] != ' ')
				&& check_surroundings(map->map, i, j))
				return (1);
		}
	}
	return (0);
}

int	main(void)
{
	t_map map;

	map.length = 6;
	map.map = malloc(sizeof(char *) * (map.length + 1));
	map.map[0] = strdup("  1   111111    1111111");
	map.map[1] = strdup("111111101 111111111");
	map.map[2] = strdup("10000111 111000001");
	map.map[3] = strdup("100001  1  100111");
	map.map[4] = strdup("10001111 110000011");
	map.map[5] = strdup("11111  111 1111111");
	map.map[6] = NULL;

	if (check_borders(&map))
		printf("Error\ninvalid map\n");
	else
		printf("Valid map\n");

	for (int i = 0; i < map.length; i++)
	{
		free(map.map[i]);
	}
	free(map.map);

	return (0);
}
