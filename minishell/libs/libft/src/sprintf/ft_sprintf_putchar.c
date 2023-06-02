/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_putchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:12:26 by mm                #+#    #+#             */
/*   Updated: 2023/05/07 01:25:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf_internal.h"

size_t	ft_def_sprintf_putchar(t_ft_sprintf_buffer *buffer, const char c)
{
	if (buffer->size <= 0)
		return (0);
	*buffer->buffer++ = c;
	buffer->size--;
	return (1);
}
