/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbrs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:07 by mm                #+#    #+#             */
/*   Updated: 2023/04/21 12:27:33 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "limits.h"

#define NUMERIC_CHARS "0123456789"
#define HEXA_CHARS_LOWER "0123456789abcdef"
#define HEXA_CHARS_UPPER "0123456789ABCDEF"
#define LONG_MAX_2 147483647

size_t	ft_def_printf_putnbr(long long n, t_ft_printf_flags flags)
{
	char	*ptr;
	size_t	count;

	ptr = ft_itoa(n);
	if (!ptr)
		return (0);
	count = 0;
	if (flags.space)
		count += ft_def_printf_putchar(' ', flags);
	else if (n > 0 && flags.positive)
		count += ft_def_printf_putchar('+', flags);
	ft_def_printf_putstr(ptr, flags);
	count += ft_strlen(ptr);
	free(ptr);
	return (count);
}

static size_t	putnbr_unsigned(unsigned long long n, t_ft_printf_flags flags)
{
	size_t	count;

	count = 1;
	if (n > 9)
		count += ft_def_printf_putnbr_unsigned(n / 10, flags);
	ft_def_printf_putchar(NUMERIC_CHARS[n % 10], flags);
	return (count);
}

size_t	ft_def_printf_putnbr_unsigned(unsigned long long n,
										t_ft_printf_flags flags)
{
	int	count;

	count = 0;
	if (flags.space)
		count += ft_def_printf_putchar(' ', flags);
	else if (flags.positive)
		count += ft_def_printf_putchar('+', flags);
	return (putnbr_unsigned(n, flags) + count);
}

static size_t	puthexadecimal(
	unsigned long long n, int upper)
{
	size_t	count;

	count = 1;
	if (n >= 16)
		count += puthexadecimal(n / 16, upper);
	if (upper)
		write(1, &HEXA_CHARS_UPPER[n % 16], 1);
	else
		write(1, &HEXA_CHARS_LOWER[n % 16], 1);
	return (count);
}

size_t	ft_def_printf_puthexadecimal(
	unsigned long long n, int upper, t_ft_printf_flags flags)
{
	size_t	count;

	count = 0;
	if (flags.hex_prefix)
	{
		if (upper)
			count += ft_def_printf_putstr("0X", flags);
		else
			count += ft_def_printf_putstr("0x", flags);
	}
	return (puthexadecimal(n, upper) + count);
}
