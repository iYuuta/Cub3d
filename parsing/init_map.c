/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:26:48 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 15:52:37 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	init_map(t_cube *cube)
{
	t_list	*current;
	char	*line;

	current = cube->lines;
	while (current)
	{
		line = current->content;
		printf("here %s\n", line);
		current = current->next;
	}
}
