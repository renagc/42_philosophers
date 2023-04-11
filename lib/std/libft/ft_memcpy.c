/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:48:16 by rgomes-c          #+#    #+#             */
/*   Updated: 2022/10/18 14:54:28 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstp;
	const char	*srcp;

	dstp = (char *)dst;
	srcp = (const char *)src;
	if (!dstp && !srcp)
		return (0);
	while (0 < n--)
		dstp[n] = srcp[n];
	return (dstp);
}
