/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:10:12 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:10:36 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	src_length;

	if (!dst || !src)
		return (0);
	n = size;
	src_length = ft_strlen(src);
	if (size > 0)
	{
		while (--n != 0 && *src != '\0')
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_length);
}
