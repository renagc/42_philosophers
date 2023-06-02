/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:27:33 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:11:00 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && (const unsigned char)*s != (const unsigned char)c)
		s++;
	if ((const unsigned char)*s == (const unsigned char)c)
		return ((char *)s);
	return (NULL);
}
