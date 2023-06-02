/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:21:29 by mm                #+#    #+#             */
/*   Updated: 2023/05/28 19:49:43 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

typedef t_get_next_line_data	t_data;

/*
	- get new line everytime we call it.
	- while the cached line doesnt end with an \n, we fetch
	- while fetching, we keep adding to the str buff the result
	- when it stops, we grab the line & discard it from the buffer
 */

static bool	define_data(t_data *data, int fd)
{
	if (fd < 0)
		return (false);
	data->defined = true;
	data->fd = fd;
	data->buffer = malloc(1 * sizeof(char));
	if (!data->buffer)
		return (false);
	data->buffer[0] = '\0';
	return (true);
}

static char	*read_from_data(t_data *data)
{
	char	*read_buffer;
	long	read_bytes;
	char	*end_l;

	read_bytes = 1;
	read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	while (!ft_strchr(data->buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(data->fd, read_buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			break ;
		read_buffer[read_bytes] = '\0';
		data->buffer = ft_strjoin_free(data->buffer, read_buffer);
	}
	if (read_bytes < 0)
		end_l = NULL;
	else if (read_bytes == 0 && ft_strlen(data->buffer) > 0)
		end_l = data->buffer + ft_strlen(data->buffer) - 1;
	else
		end_l = ft_strchr(data->buffer, '\n');
	free(read_buffer);
	return (end_l);
}

static char	*get_line_cleanup_cache(t_data *data, char *end_l)
{
	char	*line;
	char	*trimmed;
	size_t	line_len;

	line_len = end_l - data->buffer + 1;
	line = malloc((line_len + 1) * sizeof(char));
	if (!line)
	{
		free(data->buffer);
		data->buffer = NULL;
		return (NULL);
	}
	line[line_len] = '\0';
	ft_memmove(line, data->buffer, line_len);
	ft_memmove(
		data->buffer,
		data->buffer + line_len,
		ft_strlen(data->buffer) + 1 - line_len);
	trimmed = ft_strtrim(line, "\n\r");
	free(line);
	return (trimmed);
}

static void	*fallback_clear_cache(t_data *cache)
{
	if (!cache->defined)
		return (NULL);
	if (cache->buffer)
		free(cache->buffer);
	cache->defined = false;
	cache->buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data	storage[4096];
	t_data			*cache;
	char			*end_l;

	if (fd < 0)
		return (NULL);
	cache = &storage[fd];
	if (!cache->defined && !define_data(cache, fd))
		return (NULL);
	else if (cache->fd != fd)
		return (fallback_clear_cache(cache));
	end_l = read_from_data(cache);
	if (!end_l)
		return (fallback_clear_cache(cache));
	return (get_line_cleanup_cache(cache, end_l));
}
