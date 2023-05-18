/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:03 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/16 22:15:05 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_table *table)
{
	t_philo	*temp;

	temp = table->philos;
	while (temp->ph_id <= table->n_of_ph)
	{
		if (pthread_mutex_init(&temp->fork, NULL))
			return (ft_printf("Error initing mutex"));
		if (temp->ph_id == table->n_of_ph)
			break ;
		temp = temp->next;
	}
	return (1);
}

int	init_thread(t_table *table)
{
	t_philo	*temp;

	temp = table->philos;
	while (temp->ph_id <= table->n_of_ph)
	{
		if (pthread_create(&temp->thread, NULL, routine, table))
			return (ft_printf("Error creating thread"));
		if (temp->ph_id == table->n_of_ph)
			break ;
		temp = temp->next;
	}
	return (1);
}

int	join_thread(t_table *table)
{
	t_philo	*temp;

	temp = table->philos;
	while (temp->ph_id <= table->n_of_ph)
	{
		pthread_join(temp->thread, NULL);
		if (temp->ph_id == table->n_of_ph)
			break ;
		temp = temp->next;
	}
	return (1);
}
