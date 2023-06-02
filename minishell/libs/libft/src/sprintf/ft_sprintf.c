/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:19:39 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf_internal.h"

static t_ft_sprintf_flags	ft_handle_bonus(const char *format, size_t *idx)
{
	t_ft_sprintf_flags	flags;

	flags.hex_prefix = false;
	flags.positive = false;
	flags.space = false;
	flags.precision = 6;
	if (format[*idx + 1] == '#')
	{
		flags.hex_prefix = (format[*idx + 2] == 'x' || format[*idx + 2] == 'X');
		(*idx)++;
	}
	else if (format[*idx + 1] == ' ')
	{
		flags.space = true;
		(*idx)++;
	}
	else if (format[*idx + 1] == '.')
	{
		(*idx)++;
		flags.precision = ft_atoi(&format[*idx + 1]);
		while (ft_isdigit(format[*idx + 1]))
			(*idx)++;
	}
	return (flags);
}

static size_t	ft_format(\
	t_ft_sprintf_buffer *buffer, \
	const char *format, \
	va_list args, \
	size_t *idx \
)
{
	t_ft_sprintf_flags	flags;
	char				mod;

	flags = ft_handle_bonus(format, idx);
	mod = format[++(*idx)];
	if (mod == 'c')
		return (ft_def_sprintf_putchar(buffer, va_arg(args, int)));
	else if (mod == 's')
		return (ft_def_sprintf_putstr(buffer, va_arg(args, char *)));
	else if (mod == 'd' || mod == 'i')
		return (ft_def_sprintf_putnbr(buffer, va_arg(args, int), flags));
	else if (mod == 'u')
		return (ft_def_sprintf_putnbr_unsigned(buffer,
				va_arg(args, unsigned int), flags));
	else if (mod == 'x' || mod == 'X')
		return (ft_def_sprintf_puthexadecimal(buffer,
				va_arg(args, unsigned int), mod == 'X', flags));
	else if (mod == 'p')
		return (ft_def_sprintf_putaddress(buffer,
				va_arg(args, void *), flags));
	else if (mod == 'f')
		return (ft_def_sprintf_putfloat(buffer, va_arg(args, double), flags));
	else if (mod == '%')
		return (ft_def_sprintf_putchar(buffer, '%'));
	return (0);
}

int	ft_sprintf(char *str, size_t size, const char *format, ...)
{
	va_list				list;
	size_t				idx;
	size_t				count;
	t_ft_sprintf_buffer	buffer;

	idx = 0;
	count = 0;
	if (!str || !format)
		return (-1);
	va_start(list, format);
	buffer = (t_ft_sprintf_buffer){.size = size, .buffer = str};
	while (format[idx] && count < size - 1)
	{
		if (format[idx] != '%')
		{
			count += ft_def_sprintf_putchar(&buffer, format[idx++]);
			continue ;
		}
		count += ft_format(&buffer, format, list, &idx);
		idx++;
	}
	if (count < size)
		str[count] = '\0';
	va_end(list);
	return (count);
}
