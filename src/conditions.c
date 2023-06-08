/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:37:13 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/08 22:10:35 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_is_alive(t_philo *philo)
{
	pthread_mutex_lock(&table()->meal_mutex);
	if (get_program_time() - philo->last_meal >= table()->t_to_die)
	{
		write_action(philo->ph_id, "died");
		pthread_mutex_lock(&table()->dead_mutex);
		table()->ph_dead = 1;
		pthread_mutex_unlock(&table()->dead_mutex);
		pthread_mutex_unlock(&table()->meal_mutex);
		return (0);
	}
	pthread_mutex_unlock(&table()->meal_mutex);
	return (1);
}

/*
	This function checks if the philo is full;
*/
int	philo_is_full(t_philo *philo)
{
	if (!table()->n_must_eat)
		return (0);
	pthread_mutex_lock(&table()->full_mutex);
	if (philo->times_ate == table()->n_must_eat)
	{
		table()->all_ate += 1;
		pthread_mutex_unlock(&table()->full_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table()->full_mutex);
	return (0);
}

int	someone_died(void)
{
	pthread_mutex_lock(&table()->dead_mutex);
	if (table()->ph_dead)
	{
		pthread_mutex_unlock(&table()->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table()->dead_mutex);
	return (0);
}

int	philos_are_full(void)
{
	if (!table()->n_must_eat)
		return (0);
	pthread_mutex_lock(&table()->full_mutex);
	if (table()->all_ate == table()->n_of_ph)
	{
		pthread_mutex_unlock(&table()->full_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table()->full_mutex);
	return (0);
}
