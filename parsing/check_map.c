#include "Cupid.h"

void	check_valid_door(char **map, t_cube *cube)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'D' && map[i + 1])
			{
				if (j < (int)ft_strlen(map[i]) && j < (int)ft_strlen(map[i + 1])
					&& j < (int)ft_strlen(map[i - 1]))
				{
					if (!(map[i][j - 1] == '1' && map[i][j + 1] == '1')
						&& !(map[i - 1][j] == '1' && map[i + 1][j] == '1'))
						ft_error("Door must be between two walls", cube);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_map(char **map, t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1]
				|| j >= (int)ft_strlen(map[i + 1]) || j >= (int)ft_strlen(map[i
					- 1]) || ft_isspace(map[i][j - 1]) || ft_isspace(map[i][j
					+ 1]) || ft_isspace(map[i - 1][j]) || ft_isspace(map[i
					+ 1][j]))
			{
				if (ft_isin(map[i][j], "0D"))
					ft_error("Map must be surrounded by walls", cube);
				else if (ft_isin(map[i][j], "NSEW"))
					ft_error("Player can't be outside the map", cube);
			}
			j++;
		}
		i++;
	}
}

void	check_player(char **map, t_cube *cube)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_isin(map[i][j], "NSEW"))
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		ft_error("Map must have a player (N, S, E, W)", cube);
	if (count > 1)
		ft_error("Map must have only one player", cube);
}
