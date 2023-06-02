/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:03:36 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:10:22 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*buffer;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s, size);
	return (buffer);
}
