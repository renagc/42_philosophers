/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:12:26 by mm                #+#    #+#             */
/*   Updated: 2023/04/19 19:33:16 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

size_t	ft_def_printf_putchar(const char c, t_ft_printf_flags flags)
{
	(void)flags;
	write(1, &c, 1);
	return (1);
}
