/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:06:02 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:15:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		if (del)
			del(node->content);
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*lst = NULL;
}
