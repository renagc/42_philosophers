/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 13:03:49 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

size_t	ft_def_printf_format(\
	const char mod, \
	va_list args, \
	t_ft_printf_flags flags \
)
{
	if (mod == 'c')
		return (ft_def_printf_putchar(va_arg(args, int), flags));
	else if (mod == 's')
		return (ft_def_printf_putstr(va_arg(args, char *), flags));
	else if (mod == 'p')
		return (ft_def_printf_putaddress(va_arg(args, void *), flags));
	else if (mod == 'd' || mod == 'i')
		return (ft_def_printf_putnbr(va_arg(args, int), flags));
	else if (mod == 'u')
		return (ft_def_printf_putnbr_unsigned(va_arg(args, unsigned int),
				flags));
	else if (mod == 'x')
		return (ft_def_printf_puthexadecimal(va_arg(args, unsigned int), 0,
				flags));
	else if (mod == 'X')
		return (ft_def_printf_puthexadecimal(va_arg(args, unsigned int), 1,
				flags));
	else if (mod == 'f')
		return (ft_def_printf_putfloat(va_arg(args, double), flags));
	else if (mod == '%')
		return (ft_def_printf_putchar('%', flags));
	else
		return (0);
}

t_ft_printf_flags	ft_def_printf_flags(const char *format, size_t *idx)
{
	t_ft_printf_flags	flags;

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

int	ft_printf(const char *format, ...)
{
	va_list	list;
	size_t	idx;
	size_t	count;

	if (!format)
		return (-1);
	va_start(list, format);
	idx = 0;
	count = 0;
	while (format[idx])
	{
		if (format[idx] != '%')
		{
			ft_putchar_fd(format[idx++], 1);
			count++;
			continue ;
		}
		count += ft_def_printf_format(format[++idx], list, \
			ft_def_printf_flags(format, &idx));
		idx++;
	}
	va_end(list);
	return (count);
}
