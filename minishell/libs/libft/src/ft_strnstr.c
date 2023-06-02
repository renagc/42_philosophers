/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:48:19 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:09:17 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	idx;

	if (!big || !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while ((0 < (size_t)i - (size_t)len) && big[i])
	{
		idx = i;
		while (i < len && big[i++] == little[j++])
			if (little[j] == '\0')
				return ((char *)(&big[idx]));
		j = 0;
		i = idx + 1;
	}
	return (NULL);
}
