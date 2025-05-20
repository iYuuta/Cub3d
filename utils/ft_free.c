/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:44:18 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 16:51:21 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	ft_free(void)
{
	t_gc	**head;
	t_gc	*curr;
	t_gc	*temp;

	head = NULL;
	head = ft_gc();
	curr = *head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp->ptr);
		temp->ptr = NULL;
		free(temp);
		temp = NULL;
	}
	*head = NULL;
}
