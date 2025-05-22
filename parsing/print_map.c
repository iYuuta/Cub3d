/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:59:59 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/21 14:52:56 by moboulan         ###   ########.fr       */
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
	if (cube.no)
		printf("NO: [%s]\n", cube.no);
	if (cube.so)
		printf("SO: [%s]\n", cube.so);
	if (cube.we)
		printf("WE: [%s]\n", cube.we);
	if (cube.ea)
		printf("EA: [%s]\n", cube.ea);
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
