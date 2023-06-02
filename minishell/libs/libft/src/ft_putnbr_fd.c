/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:05:38 by mm                #+#    #+#             */
/*   Updated: 2023/05/17 09:12:21 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

#define NUMERIC_CHARS "0123456789"
#define INT_MAX_2 147483648

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 1)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == INT_MIN)
		{
			ft_putchar_fd('2', fd);
			n = INT_MAX_2;
		}
		else
			n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(NUMERIC_CHARS[n % 10], fd);
}
