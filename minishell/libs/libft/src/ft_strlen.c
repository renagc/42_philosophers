/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:21:29 by mm                #+#    #+#             */
/*   Updated: 2023/05/15 02:16:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

size_t	ft_strlen(const char *str)
{
	int	idx;

	if (!str)
		return (0);
	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}
