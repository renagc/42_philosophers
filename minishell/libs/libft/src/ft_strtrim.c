/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:53:22 by mm                #+#    #+#             */
/*   Updated: 2023/04/21 12:27:33 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_set(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static void	compute_size_from_trimmed_chars(
	const char *str,
	const char *set,
	size_t *start_trim,
	size_t *end_trim)
{
	const char	*ptr;
	size_t		str_length;

	str_length = ft_strlen(str);
	ptr = str;
	*start_trim = 0;
	while (is_char_in_set(*ptr++, set) && ptr < (str + str_length))
		(*start_trim)++;
	ptr = str + str_length - 1;
	*end_trim = 0;
	while (is_char_in_set(*ptr--, set) && (ptr >= (str)))
		(*end_trim)++;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	long long	s1_length;
	size_t		start_trim;
	size_t		end_trim;

	if (!s1)
		return ((char *)s1);
	if (!set)
		return (ft_strdup(s1));
	s1_length = ft_strlen(s1);
	compute_size_from_trimmed_chars(s1, set, &start_trim, &end_trim);
	s1_length -= (start_trim + end_trim);
	if (s1_length < 0)
		s1_length = 0;
	str = malloc((s1_length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start_trim, s1_length + 1);
	return (str);
}
