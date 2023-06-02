/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:08:52 by mm                #+#    #+#             */
/*   Updated: 2023/05/28 23:19:32 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static size_t	compute_integer_size(long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	sanitize_input(char *str, long *n)
{
	size_t	tmp_count;

	tmp_count = 0;
	if (*n < 0)
	{
		str[tmp_count++] = '-';
		*n = -(*n);
	}
	else if (*n == 0)
		str[tmp_count++] = '0';
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	size_t	length;

	n = nbr;
	length = compute_integer_size(n);
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	sanitize_input(str, &n);
	while (n > 0)
	{
		str[length-- - 1] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
