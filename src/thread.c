/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:03 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/12 15:25:07 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		if (pthread_mutex_init(&temp->mutex, NULL))
			return (ft_printf("Error initing mutex"));
		temp = temp->next;
	}
	return (1);
}

int	destroy_mutex(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		if (pthread_mutex_destroy(&temp->mutex))
			return (ft_printf("Error initing mutex"));
		temp = temp->next;
	}
	return (1);
}

int	init_thread(t_philo	*philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		if (pthread_create(&temp->thread, NULL, routine, NULL))
			return (ft_printf("Error creating thread"));
		temp = temp->next;
	}
	return (1);
}

int	join_thread(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
	}
	return (1);
}
