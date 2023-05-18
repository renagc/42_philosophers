/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:54:45 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/16 16:32:46 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_printlst(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		ft_printf("philo_list---------\nid: %d\n", temp->ph_id);
		temp = temp->next;
	}
}
