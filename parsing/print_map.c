/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:59:59 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/19 19:32:43 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

// to delete later

void	print_map(t_list *list)
{
	t_list	*current;

	if (!list)
		printf("map is empty\n");
	current = list;
	while (current)
	{
		printf("%s", (char *)current->content);
		current = current->next;
	}
	printf("\n");
}
