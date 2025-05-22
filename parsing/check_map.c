#include "Cupid.h"
#include <string.h>

int check_existence(t_map *map, int j, int i)
{
	if (j == 0 || j + 1 == map->length)
		return (1);
	if (i >= strlen(map->map[j - 1]) || i >= strlen(map->map[j + 1]))
		return (1);
	return (0);
}

int check_surroundings(char **str, int i, int j)
{
	int track;

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
	int i;
	int j;
	int flag;

	j = -1;
	while (map->map[++j])
	{
		i = -1;
		while (map->map[j][++i])
		{
			if (!strchr("10 ", map->map[j][i]))
				return (1);
			if (check_existence(map, j, i) && (map->map[j][i] != '1' && map->map[j][i] != ' '))
				return (1);
			else if ((map->map[j][i] != '1' && map->map[j][i] != ' ') && check_surroundings(map->map, i, j))
				return (1);
		}
	}
	return (0);
}
