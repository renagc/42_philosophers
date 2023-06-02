/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:35:24 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:13:10 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s || !n)
		return (NULL);
	while (n-- > 0)
		if ((unsigned char)*(char *)s++ == (unsigned char)c)
			return ((void *)(s - 1));
	return (NULL);
}
