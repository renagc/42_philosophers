/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_putaddress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:13:07 by mm                #+#    #+#             */
/*   Updated: 2023/05/07 01:49:04 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf_internal.h"

#define HEXA_CHARS "0123456789abcdef"

size_t	ft_def_sprintf_putaddress(t_ft_sprintf_buffer *buffer, void *addr,
			t_ft_sprintf_flags flags)
{
	flags.hex_prefix = true;
	return (ft_def_sprintf_puthexadecimal(\
		buffer, \
		(unsigned long long)addr, \
		false, \
		flags \
	));
}
