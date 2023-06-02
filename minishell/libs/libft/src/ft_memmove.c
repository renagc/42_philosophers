/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:25:28 by mm                #+#    #+#             */
/*   Updated: 2023/04/13 01:39:21 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;

	if (!dest && !src)
		return (NULL);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	else
	{
		tmp = dest;
		dest += n;
		src += n;
		while (n--)
			*(char *)--dest = *(char *)--src;
	}
	return (tmp);
}
