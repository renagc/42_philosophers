/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putfloat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:07:03 by martiper          #+#    #+#             */
/*   Updated: 2023/05/07 03:32:52 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

/*
	Output a float number with the given precision.
 */
size_t	ft_def_printf_putfloat(double n, t_ft_printf_flags flags)
{
	size_t		len;
	double		dec;
	int			i;

	len = ft_def_printf_putnbr((int)n, flags);
	if (flags.precision > 0)
	{
		ft_def_printf_putchar('.', flags);
		len++;
		dec = n - (int)n;
		i = 0;
		while (i < flags.precision)
			i++;
		while (i-- > 0)
		{
			dec *= 10;
			len += ft_def_printf_putnbr((int)dec, flags);
			dec -= (int)dec;
		}
	}
	return (len);
}
