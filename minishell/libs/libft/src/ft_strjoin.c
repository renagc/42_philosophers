/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:47:05 by mm                #+#    #+#             */
/*   Updated: 2023/04/23 07:01:56 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_length;
	size_t	s2_length;
	size_t	length;

	if (!s2)
		return (ft_strdup(s1));
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	length = s1_length + s2_length;
	join = malloc((length + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1_length + 1);
	ft_strlcpy(join + s1_length, s2, s2_length + 1);
	join[length] = '\0';
	return (join);
}
