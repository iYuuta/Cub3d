/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:32:30 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 19:50:03 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

static char	*get_value(char *str)
{
	char	*end;

	if (*str && !ft_isspace(*str))
		return (ft_error("Need space between element and value"), NULL);
	while (*str && ft_isspace(*str))
		str++;
	if (!*str)
		return (ft_error("Empty element value"), NULL);
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace(*end))
		end--;
	return (ft_substr(str, 0, end - str + 1));
}

static int	add_element(char *str, t_cube *cube)
{
	static int	dup[6];

	if (dup[0] > 1 || dup[1] > 1 || dup[2] > 1
		|| dup[3] > 1 || dup[4] > 1 || dup[5] > 1)
		ft_error("Duplicate Element");
	if (!ft_strncmp(str, "NO", 2))
		return (dup[0]++, str += 2, cube->no = get_value(str), 1);
	else if (!ft_strncmp(str, "SO", 2))
		return (dup[1]++, str += 2, cube->so = get_value(str), 1);
	else if (!ft_strncmp(str, "WE", 2))
		return (dup[2]++, str += 2, cube->we = get_value(str), 1);
	else if (!ft_strncmp(str, "EA", 2))
		return (dup[3]++, str += 2, cube->ea = get_value(str), 1);
	else if (!ft_strncmp(str, "F", 1))
		return (dup[4]++, str++, cube->f = get_value(str), 1);
	else if (!ft_strncmp(str, "C", 1))
		return (dup[5]++, str++, cube->c = get_value(str), 1);
	else if (*str && !ft_isin(*str, "01"))
		ft_error("Invalid Identifier");
	return (0);
}

void	init_elements(t_cube *cube)
{
	t_list	*current;
	char	*line;

	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->ea = NULL;
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
	if (!cube->no || !cube->so || !cube->we
		|| !cube->ea || !cube->f || !cube->c)
		ft_error("Missing element");
}
