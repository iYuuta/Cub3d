/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:57:13 by moboulan          #+#    #+#             */
/*   Updated: 2025/05/20 16:45:11 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cupid.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = (t_list *)ft_malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->content = content;
	t->next = NULL;
	t->prev = NULL;
	return (t);
}
