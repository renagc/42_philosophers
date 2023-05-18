/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:57 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/18 15:31:28 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_write(t_philo *philo, int action, unsigned long long time)
{
	pthread_mutex_lock(&philo->table_data->write_mutex);
	if (action == FORK)
		ft_printf("%d %d has taken a fork\n", time, philo->ph_id);
	else if (action == EAT)
		ft_printf("%d %d is eating\n", time, philo->ph_id);
	else if (action == SLEEP)
		ft_printf("%d %d is sleeping\n", time, philo->ph_id);
	else if (action == THINK)
		ft_printf("%d %d is thinking\n", time, philo->ph_id);
	else if (action == DEAD)
		ft_printf("%d %d died\n", time, philo->ph_id);
	pthread_mutex_unlock(&philo->table_data->write_mutex);
}

void	f_eat(t_philo *philo)
{
	unsigned long long	time;

	pthread_mutex_lock(&philo->fork);
	f_write(philo, FORK, get_time() - philo->table_data->start_time);
	pthread_mutex_lock(&philo->next->fork);
	f_write(philo, FORK, get_time() - philo->table_data->start_time);
	time = get_time();
	pthread_mutex_lock(&philo->table_data->time_mutex);
	philo->last_time_ate = time - philo->table_data->start_time;
	pthread_mutex_unlock(&philo->table_data->time_mutex);
	f_write(philo, EAT, get_time() - philo->table_data->start_time);
	usleep(philo->table_data->t_to_eat * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	f_think(t_philo *philo)
{
	f_write(philo, THINK, get_time() - philo->table_data->start_time);
}

void	f_sleep(t_philo *philo)
{
	f_write(philo, SLEEP, get_time() - philo->table_data->start_time);
	usleep(philo->table_data->t_to_sleep * 1000);
}
