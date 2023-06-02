/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:19:32 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:14:24 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, int (*f)(void *))
{
	if (!f)
		return (NULL);
	while (lst)
	{
		if (f(lst->content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
