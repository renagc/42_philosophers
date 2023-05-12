/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:54:45 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/12 08:59:47 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_printlst(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		ft_printf("philo_list---------\nid: %d\nt_to_die: %d\nt_to_eat: %d\nt_to_sleep: %d\nn_must_eat: %d\n", temp->ph_id, temp->t_to_eat, temp->t_to_eat, temp->t_to_sleep, temp->n_must_eat);
		temp = temp->next;
	}
}
