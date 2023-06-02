/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:45:12 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 13:06:45 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include "libft.h"
# include "stdlib.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_ft_printf_flags
{
	bool	space;
	bool	positive;
	bool	hex_prefix;
	int		precision;
}			t_ft_printf_flags;

size_t				ft_def_printf_putaddress(\
	void *n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_printf_putstr(\
	const char *str, \
	t_ft_printf_flags flags \
);
size_t				ft_def_printf_putchar(\
	const char c, \
	t_ft_printf_flags flags \
);
size_t				ft_def_printf_putnbr(\
	long long n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_printf_putnbr_unsigned(\
	unsigned long long n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_printf_puthexadecimal(\
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags \
);
size_t				ft_def_printf_putfloat(\
	double n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_printf_format(\
	const char mod, \
	va_list args, \
	t_ft_printf_flags flags \
);
t_ft_printf_flags	ft_def_printf_flags(const char *format, size_t *idx);

#endif
