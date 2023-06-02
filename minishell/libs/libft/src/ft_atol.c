/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:55:00 by mm                #+#    #+#             */
/*   Updated: 2023/05/31 19:07:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(char c)
{
	return (
		c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v'
	);
}

long	ft_atol(const char *str)
{
	size_t	i;
	int		signal;
	long	result;

	i = 0;
	if (!str)
		return (0);
	while (ft_is_whitespace(str[i]))
		i++;
	signal = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	result = 0;
	while (str[i] && ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * signal);
}

long long	ft_atoll(const char *str)
{
	size_t		i;
	int			signal;
	long long	result;

	i = 0;
	if (!str)
		return (0);
	while (ft_is_whitespace(str[i]))
		i++;
	signal = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	result = 0;
	while (str[i] && ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * signal);
}
