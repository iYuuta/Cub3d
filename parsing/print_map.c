/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:59:59 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/23 11:38:18 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

// to delete later

void	print_lines(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		printf("%s", (char *)current->content);
		current = current->next;
	}
	printf("\n");
}

void	print_elements(t_cube cube)
{
	if (cube.no.name)
		printf("NO: [%s]\n", cube.no.name);
	if (cube.so.name)
		printf("SO: [%s]\n", cube.so.name);
	if (cube.we.name)
		printf("WE: [%s]\n", cube.we.name);
	if (cube.ea.name)
		printf("EA: [%s]\n", cube.ea.name);
	if (cube.f)
		printf("F : [%s]\n", cube.f);
	if (cube.c)
		printf("C : [%s]\n", cube.c);
}

void	print_rgb(t_rgb rgb)
{
	printf("Red: [%d]\n", rgb.red);
	printf("Green: [%d]\n", rgb.green);
	printf("Blue: [%d]\n", rgb.blue);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}
