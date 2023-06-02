/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_putnbrs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:07 by mm                #+#    #+#             */
/*   Updated: 2023/05/07 01:45:49 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf_internal.h"
#include <limits.h>

#define NUMERIC_CHARS "0123456789"
#define HEXA_CHARS_LOWER "0123456789abcdef"
#define HEXA_CHARS_UPPER "0123456789ABCDEF"
#define LONG_MAX_2 147483647

size_t	ft_def_sprintf_putnbr(\
	t_ft_sprintf_buffer *buffer, \
	long long n, \
	t_ft_sprintf_flags flags \
)
{
	char	*ptr;
	size_t	count;

	count = 0;
	ptr = ft_itoa(n);
	if (!ptr)
		return (0);
	if (flags.space && buffer->size > 0)
		count += ft_def_sprintf_putchar(buffer, ' ');
	if (flags.positive && n > 0 && buffer->size > 0)
		count += ft_def_sprintf_putchar(buffer, '+');
	count += ft_def_sprintf_putstr(buffer, ptr);
	free(ptr);
	return (count);
}

size_t	ft_def_sprintf_putnbr_unsigned(t_ft_sprintf_buffer *buffer,
			unsigned long long n, t_ft_sprintf_flags flags)
{
	size_t	count;

	count = 1;
	if (n >= 10)
		count += ft_def_sprintf_putnbr_unsigned(buffer, n / 10, flags);
	if (buffer->size > 0)
		count += ft_def_sprintf_putchar(buffer, NUMERIC_CHARS[n % 10]);
	return (count);
}

static size_t	puthexadecimal(
	t_ft_sprintf_buffer *buffer, unsigned long long n, int upper)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += puthexadecimal(buffer, n / 10, upper);
	if (upper)
		count += ft_def_sprintf_putchar(buffer, HEXA_CHARS_UPPER[n % 16]);
	else
		count += ft_def_sprintf_putchar(buffer, HEXA_CHARS_LOWER[n % 16]);
	return (count);
}

size_t	ft_def_sprintf_puthexadecimal(t_ft_sprintf_buffer *buffer,
			unsigned long long n, int upper, t_ft_sprintf_flags flags)
{
	size_t	count;

	count = 0;
	if (flags.hex_prefix)
	{
		if (upper)
			count += ft_def_sprintf_putstr(buffer, "0X");
		else
			count += ft_def_sprintf_putstr(buffer, "0x");
	}
	return (puthexadecimal(buffer, n, upper) + count);
}
