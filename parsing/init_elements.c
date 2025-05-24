#include "Cupid.h"

static char	*get_value(char *str)
{
	char	*end;

	if (*str && !ft_isspace(*str))
		return (ft_error("Need space between element and value"), NULL);
	while (*str && ft_isspace(*str))
		str++;
	if (!*str)
		return (ft_error("Empty Element value"), NULL);
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace(*end))
		end--;
	return (ft_substr(str, 0, end - str + 1));
}

static int	add_element(char *str, t_cube *cube)
{
	static int	dup[6];

	if (dup[0] > 1 || dup[1] > 1 || dup[2] > 1 || dup[3] > 1 || dup[4] > 1
		|| dup[5] > 1)
		ft_error("Duplicate Element");
	if (!ft_strncmp(str, "NO", 2))
		return (dup[0]++, str += 2, cube->no.name = get_value(str), 1);
	else if (!ft_strncmp(str, "SO", 2))
		return (dup[1]++, str += 2, cube->so.name = get_value(str), 1);
	else if (!ft_strncmp(str, "WE", 2))
		return (dup[2]++, str += 2, cube->we.name = get_value(str), 1);
	else if (!ft_strncmp(str, "EA", 2))
		return (dup[3]++, str += 2, cube->ea.name = get_value(str), 1);
	else if (!ft_strncmp(str, "F", 1))
		return (dup[4]++, str++, cube->f = get_value(str), 1);
	else if (!ft_strncmp(str, "C", 1))
		return (dup[5]++, str++, cube->c = get_value(str), 1);
	else if (*str && !ft_isin(*str, "01NSEW"))
		ft_error("Invalid Map Character");
	return (0);
}

static void	init_texture(t_cube *cube)
{
	cube->no.texture = mlx_xpm_file_to_image(cube->mlx, cube->no.name,
			&cube->no.height, &cube->no.width);
	if (!cube->no.texture)
		ft_error("Failed to load the NO texture file");
	cube->so.texture = mlx_xpm_file_to_image(cube->mlx, cube->so.name,
			&cube->so.height, &cube->so.width);
	if (!cube->so.texture)
		ft_error("Failed to load the SO texture file");
	cube->we.texture = mlx_xpm_file_to_image(cube->mlx, cube->we.name,
			&cube->we.height, &cube->we.width);
	if (!cube->we.texture)
		ft_error("Failed to load the WE texture file");
	cube->ea.texture = mlx_xpm_file_to_image(cube->mlx, cube->ea.name,
			&cube->ea.height, &cube->ea.width);
	if (!cube->ea.texture)
		ft_error("Failed to load the EA texture file");
}

void	init_elements(t_cube *cube)
{
	t_list	*current;
	char	*line;

	cube->no.name = NULL;
	cube->so.name = NULL;
	cube->we.name = NULL;
	cube->ea.name = NULL;
	cube->f = NULL;
	cube->c = NULL;
	current = cube->lines;
	while (current)
	{
		line = current->content;
		while (*line && ft_isspace(*line))
			line++;
		if (add_element(line, cube))
			current->content = NULL;
		current = current->next;
	}
	if (!cube->no.name || !cube->so.name || !cube->we.name || !cube->ea.name
		|| !cube->f || !cube->c)
		ft_error("Missing Element");
	init_texture(cube);
}
