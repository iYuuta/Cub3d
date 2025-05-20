/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:26:48 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 17:17:20 by moboulan         ###   ########.fr       */
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
		if (line && ft_strcmp(line, "\n"))
			break ;
		current = current->next;
	}
	return (current);
}

void	init_map(t_cube *cube)
{
	t_list	*current;
	char	*line;

	current = skip_newlines(cube);
	while (current)
	{
		line = current->content;
		if (line && !ft_strcmp(line, "\n"))
			ft_error("Incorrect map structure");
		current = current->next;
	}
}
