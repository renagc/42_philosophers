/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:30:38 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:09:03 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*orig;

	if (!s)
		return (NULL);
	orig = s;
	while (*s++)
		;
	s--;
	while (s != orig && *s != (unsigned char)c)
		s--;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
