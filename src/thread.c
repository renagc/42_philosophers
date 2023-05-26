/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:03 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/26 10:42:12 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	destroy_mutex(void)
{
	t_philo	*temp;

	temp = table()->ph_lst;
	while (temp)
	{
		if (pthread_mutex_destroy(&temp->fork))
			return (ft_printf("Error initing mutex"));
		if (temp->ph_id == table()->n_of_ph)
			break ;
		temp = temp->next;
	}
	pthread_mutex_init(&table()->meal_mutex, NULL);
	pthread_mutex_init(&table()->dead_mutex, NULL);
	pthread_mutex_init(&table()->write_mutex, NULL);
	pthread_mutex_init(&table()->time_mutex, NULL);
	return (1);
}

int	join_thread(void)
{
	t_philo	*temp;

	temp = table()->ph_lst;
	while (temp)
	{
		pthread_join(temp->thread, NULL);
		if (temp->ph_id == table()->n_of_ph)
			break ;
		temp = temp->next;
	}
	pthread_join(table()->thread, NULL);
	return (1);
}

int	someone_died(void)
{
	pthread_mutex_lock(&table()->dead_mutex);
	if (table()->ph_dead == 1)
	{
		pthread_mutex_unlock(&table()->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table()->dead_mutex);
	return (0);
}

int	one_philo(t_philo *philo)
{
	if (table()->n_of_ph == 1)
	{
		f_write(philo, FORK, get_program_time());
		f_write(philo, DEAD, get_program_time());
		return (1);
	}
	return (0);
}

void	*routine(void *route)
{
	t_philo	*philo;

	philo = (t_philo *)route;
	if (one_philo(philo))
		return (NULL);
	if (philo->ph_id % 2 == 0)
		usleep(200);
	while (!someone_died())
	{
		f_eat(philo);
		if (philo->n_meals == 0)
			break ;
		f_sleep(philo);
		f_think(philo);
	}
	return (NULL);
}

void	*routine_control(void *route)
{
	t_philo				*lst;

	lst = (t_philo *)route;
	if (table()->n_of_ph == 1)
		return (NULL);
	while (lst)
	{
		pthread_mutex_lock(&table()->meal_mutex);
		if (table()->phs_ate == table()->n_of_ph)
		{
			pthread_mutex_unlock(&table()->meal_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&table()->meal_mutex);
		if ((get_program_time() - lst->last_meal) > table()->t_to_die && lst->last_meal)
		{
			pthread_mutex_lock(&table()->dead_mutex);
			table()->ph_dead = 1;
			pthread_mutex_unlock(&table()->dead_mutex);
			ft_printf("%d %d died\n", get_program_time(), lst->ph_id);
			return (NULL);
		}
		lst = lst->next;
	}
	return (NULL);
}
