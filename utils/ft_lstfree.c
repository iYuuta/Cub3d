/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:57:13 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/17 18:31:07 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*ptr;
	t_list	*node;

	ptr = *lst;
	if (!ptr)
		return ;
	while (ptr)
	{
		node = ptr->next;
		free(ptr);
		ptr = node;
	}
}
