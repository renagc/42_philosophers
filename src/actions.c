/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:57 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/26 10:19:07 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_write(t_philo *philo, int action, unsigned long long time)
{
	if (someone_died())
		return ;
	pthread_mutex_lock(&table()->write_mutex);
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
	pthread_mutex_unlock(&table()->write_mutex);
}

void	f_eat(t_philo *philo)
{
	while (philo->next->fork_in_use == 1)
		continue ;
	pthread_mutex_lock(&philo->fork);
	philo->fork_in_use = 1;
	f_write(philo, FORK, get_program_time());
	pthread_mutex_lock(&philo->next->fork);
	philo->next->fork_in_use = 1;
	f_write(philo, FORK, get_program_time());
	f_write(philo, EAT, get_program_time());
	pthread_mutex_lock(&table()->meal_mutex);
	table()->all_ate += 1;
	pthread_mutex_unlock(&table()->meal_mutex);
	philo->last_meal = get_program_time();
	f_usleep(table()->t_to_eat);
	pthread_mutex_unlock(&philo->fork);
	philo->fork_in_use = 0;
	pthread_mutex_unlock(&philo->next->fork);
	philo->next->fork_in_use = 0;
	philo->n_meals -= 1;
	if (philo->n_meals == 0)
	{
		pthread_mutex_lock(&table()->meal_mutex);
		table()->phs_ate += 1;
		pthread_mutex_unlock(&table()->meal_mutex);
	}
}

void	f_think(t_philo *philo)
{
	f_write(philo, THINK, get_program_time());
}

void	f_sleep(t_philo *philo)
{
	f_write(philo, SLEEP, get_program_time());
	f_usleep(table()->t_to_sleep);
}
