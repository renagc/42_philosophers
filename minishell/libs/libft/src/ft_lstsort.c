/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:52:10 by martiper          #+#    #+#             */
/*   Updated: 2023/05/17 09:13:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Sorts a double linked list (with next & prev pointers)
	Callback returns 1, 0 or -1
 */
void	ft_lstsort(t_list *lst, int (*fn)(void *a, void *b))
{
	t_list	*tmp;
	void	*content;

	if (!lst || !fn)
		return ;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (fn(lst->content, tmp->content) > 0)
			{
				content = lst->content;
				lst->content = tmp->content;
				tmp->content = content;
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}
