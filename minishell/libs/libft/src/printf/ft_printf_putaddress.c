/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putaddress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:13:07 by mm                #+#    #+#             */
/*   Updated: 2023/04/21 12:27:33 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#define HEXA_CHARS "0123456789abcdef"

static void	address_to_str(size_t address, char **str)
{
	if (address >= 16)
	{
		address_to_str(address / 16, str);
		address = address % 16;
	}
	if (address < 16)
	{
		**str = HEXA_CHARS[address];
		(*str)++;
	}
}

size_t	ft_def_printf_putaddress(void *address, t_ft_printf_flags flags)
{
	char	address_chars[17];
	char	*iter;

	if (!address)
		return (ft_def_printf_putstr("(nil)", flags));
	ft_def_printf_putstr("0x", flags);
	iter = address_chars;
	address_to_str((size_t)address, &iter);
	address_chars[iter - address_chars] = '\0';
	return (ft_def_printf_putstr(address_chars, flags) + 2);
}
