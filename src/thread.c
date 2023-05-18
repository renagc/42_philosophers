/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:03 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/18 15:47:30 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp->ph_id <= philos->table_data->n_of_ph)
	{
		if (pthread_mutex_init(&temp->fork, NULL))
			return (ft_printf("Error initing mutex"));
		if (temp->ph_id == philos->table_data->n_of_ph)
			break ;
		temp = temp->next;
	}
	pthread_mutex_init(&temp->table_data->dead_mutex, NULL);
	pthread_mutex_init(&temp->table_data->write_mutex, NULL);
	pthread_mutex_init(&temp->table_data->time_mutex, NULL);
	return (1);
}

int	destroy_mutex(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp->ph_id <= philos->table_data->n_of_ph)
	{
		if (pthread_mutex_destroy(&temp->fork))
			return (ft_printf("Error initing mutex"));
		if (temp->ph_id == philos->table_data->n_of_ph)
			break ;
		temp = temp->next;
	}
	pthread_mutex_destroy(&temp->table_data->dead_mutex);
	pthread_mutex_destroy(&temp->table_data->write_mutex);
	pthread_mutex_destroy(&temp->table_data->time_mutex);
	return (1);
}

int	init_thread(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		if (pthread_create(&temp->thread, NULL, routine, temp))
			return (ft_printf("Error creating thread"));
		if (temp->ph_id == philos->table_data->n_of_ph)
			break ;
		temp = temp->next;
	}
	return (1);
}

int	join_thread(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp->ph_id <= philos->table_data->n_of_ph)
	{
		pthread_join(temp->thread, NULL);
		if (temp->ph_id == philos->table_data->n_of_ph)
			break ;
		temp = temp->next;
	}
	return (1);
}
