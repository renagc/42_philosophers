/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:21:25 by mm                #+#    #+#             */
/*   Updated: 2023/05/07 00:23:28 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	size_t	s1_length;
	size_t	s2_length;
	size_t	length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	length = s1_length + s2_length;
	join = malloc((length + 1) * sizeof(char));
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(join, s1, s1_length + 1);
	ft_strlcpy(join + s1_length, s2, s2_length + 1);
	join[length] = '\0';
	free(s1);
	return (join);
}
