/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:41:48 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/23 10:08:52 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}
