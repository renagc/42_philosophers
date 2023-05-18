/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:37:13 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/18 16:28:36 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	f_all_alive(t_philo *philo)
{
	(void) philo;
	return (1);
}

int	check_dead(t_philo *philos)
{
	t_philo	*temp;
	unsigned long long	time;

	temp = philos;
	time = get_time();
	while (temp)
	{
		time = get_time() - temp->table_data->start_time;
		if (temp->table_data->t_to_die < time && time != 0)
		{
			printf("aqui esta o time: %lld\n", time);
			temp->table_data->dead_flag = 1;
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
