/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:59:59 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 02:25:30 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

// to delete later

void	print_map(t_list *list)
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

void	print_identifiers(t_map map)
{
	if (map.no)
		printf("NO: [%s]\n", map.no);
	if (map.so)
		printf("SO: [%s]\n", map.so);
	if (map.we)
		printf("WE: [%s]\n", map.we);
	if (map.ea)
		printf("EA: [%s]\n", map.ea);
	if (map.f)
		printf("F : [%s]\n", map.f);
	if (map.c)
		printf("C : [%s]\n", map.c);
}
