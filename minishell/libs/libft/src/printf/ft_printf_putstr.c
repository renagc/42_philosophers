/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2023/04/19 19:33:44 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

size_t	ft_def_printf_putstr(const char *str, t_ft_printf_flags flags)
{
	size_t	count;

	if (!str)
		return (ft_def_printf_putstr("(null)", flags));
	(void)flags;
	count = ft_strlen(str);
	write(1, str, count);
	return (count);
}
