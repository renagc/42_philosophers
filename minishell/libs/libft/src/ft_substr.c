/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:42:35 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:08:36 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_length;
	char	*substr;

	str_length = ft_strlen(s);
	if (!s || start >= str_length)
		return (ft_strdup(""));
	if (len > str_length - start)
		len = str_length - start;
	substr = ft_calloc(sizeof(char), len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
