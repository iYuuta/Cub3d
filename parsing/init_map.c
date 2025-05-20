/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:26:48 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 19:59:02 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

static t_list	*skip_newlines(t_cube *cube)
{
	char	*line;
	t_list	*current;

	current = cube->lines;
	while (current)
	{
		line = current->content;
		if (line && !ft_isallspace(line))
			break ;
		current = current->next;
	}
	return (current);
}

static void	check_characters(char *line)
{
	if (!line)
		return ;
	while (*line)
	{
		if (!ft_isin(*line, "10NSEW") && !ft_isspace(*line))
			ft_error("Invalid Map Character");
		line++;
	}
}

void	init_map(t_cube *cube)
{
	t_list	*current;
	t_list	*next;
	char	*line;
	char	*next_line;
	int		i;

	i = 0;
	current = skip_newlines(cube);
	cube->map = ft_malloc(ft_lstsize(current) * sizeof(char *));
	while (current)
	{
		line = current->content;
		next = current->next;
		if (next)
			next_line = next->content;
		else
			next_line = NULL;
		if (line && !ft_isallspace(line) && current->next
			&& ft_isallspace(next_line))
			ft_error("Incorrect Map Structure: one or more empty lines");
		check_characters(line);
		cube->map[i++] = ft_strdup(line);
		current = current->next;
	}
}
