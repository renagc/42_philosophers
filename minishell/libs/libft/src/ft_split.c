/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:36 by martiper          #+#    #+#             */
/*   Updated: 2023/05/24 16:33:50 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	count_letters_and_words(
	const char *str,
	const char *set,
	size_t *letters,
	size_t *words)
{
	bool	is_on_word;

	if (!str)
		return (false);
	*letters = 0;
	*words = 0;
	is_on_word = false;
	while (*str)
	{
		if (ft_strchr(set, *str) == NULL)
		{
			if (!is_on_word)
			{
				(*words)++;
				is_on_word = true;
			}
			(*letters)++;
		}
		else
			is_on_word = false;
		str++;
	}
	return (true);
}

static void	fill_buffers(
	const char *str,
	const char *set,
	char **ptrs,
	char *buffer)
{
	bool	is_on_word;

	is_on_word = false;
	while (*str)
	{
		if (ft_strchr(set, *str) == NULL)
		{
			*buffer = *str;
			if (!is_on_word)
			{
				is_on_word = true;
				*ptrs++ = buffer;
			}
			buffer++;
		}
		else
		{
			if (is_on_word)
			{
				*buffer++ = '\0';
				is_on_word = false;
			}
		}
		str++;
	}
}

static void	*cleanup_malloc_null(
	char **ptrs,
	char *buffer,
	size_t size)
{
	if (ptrs)
	{
		while (size > 0)
		{
			free(ptrs[--size]);
		}
		if (size == 0)
			free(ptrs);
	}
	if (buffer)
		free(buffer);
	return (NULL);
}

void	ft_split_free(
	char **split
)
{
	size_t	idx;

	idx = 0;
	if (!split)
		return ;
	while (split[idx])
		free(split[idx++]);
	free(split);
}

char	**ft_split(
	char const *s,
	char *set)
{
	size_t	words;
	size_t	letters;
	char	**ptrs;
	char	**tmp;
	char	*buffer;

	if (!count_letters_and_words(s, set, &letters, &words))
		return (NULL);
	ptrs = ft_calloc(sizeof(char *), words + 1);
	if (!ptrs)
		return (NULL);
	buffer = ft_calloc(sizeof(char), letters + words);
	if (!buffer)
		return (cleanup_malloc_null(ptrs, buffer, 0));
	fill_buffers(s, set, ptrs, buffer);
	tmp = ptrs;
	while (*tmp)
	{
		*tmp = ft_strdup(*tmp);
		if (!*tmp)
			return (cleanup_malloc_null(ptrs, buffer, tmp - ptrs));
		tmp++;
	}
	free(buffer);
	return (ptrs);
}
