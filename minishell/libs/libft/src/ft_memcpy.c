/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:52:17 by mm                #+#    #+#             */
/*   Updated: 2023/04/12 16:44:18 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*orig;

	if (!dest && !src)
		return (NULL);
	orig = dest;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (orig);
}
