/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:03 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/07 01:42:36 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	destroy_mutex(void)
{
	t_list	*temp;
	int		i;

	temp = table()->ph_lst;
	i = 0;
	while (++i <= table()->n_of_ph)
	{
		if (pthread_mutex_destroy(&((t_philo *)temp->content)->fork))
			return (ft_printf("Error initing mutex"));
		temp = temp->next;
	}
	pthread_mutex_destroy(&table()->fork_mutex);
	pthread_mutex_destroy(&table()->meal_mutex);
	pthread_mutex_destroy(&table()->dead_mutex);
	pthread_mutex_destroy(&table()->write_mutex);
	pthread_mutex_destroy(&table()->time_mutex);
	pthread_mutex_destroy(&table()->full_mutex);
	return (1);
}

int	join_thread(void)
{
	t_list	*temp;
	int		i;

	temp = table()->ph_lst;
	i = 0;
	while (++i <= table()->n_of_ph)
	{
		if (pthread_join(((t_philo *)temp->content)->thread, NULL))
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*
	This function checks if the philo is full;
*/
int	philo_is_full(t_philo *philo)
{
	if (!table()->n_must_eat)
		return (0);
	if (philo->times_ate == table()->n_must_eat)
	{
		pthread_mutex_lock(&table()->full_mutex);
		table()->all_ate += 1;
		pthread_mutex_unlock(&table()->full_mutex);
		return (1);
	}
	return (0);
}

int	philos_are_alive(void)
{
	pthread_mutex_lock(&table()->dead_mutex);
	if (table()->ph_dead == 1)
	{
		pthread_mutex_unlock(&table()->dead_mutex);
		return (0);
	}
	pthread_mutex_unlock(&table()->dead_mutex);
	return (1);
}

/*
	Routine for each thread;
*/
void	*routine(void *route)
{
	t_list	*temp;

	temp = (t_list *)route;
	if (table()->n_of_ph == 1)
	{
		write_action(((t_philo *)temp->content)->ph_id, "has taken a fork");
		return (NULL);
	}
	if (((t_philo *)temp->content)->ph_id % 2 == 0)
		usleep(200);
	while (philos_are_alive() && !philo_is_full((t_philo *)temp->content))
	{
		philo_eats(temp);
		write_action(((t_philo *)temp->content)->ph_id, "is sleeping");
		f_usleep(table()->t_to_sleep);
		write_action(((t_philo *)temp->content)->ph_id, "is thinking");
	}
	return (NULL);
}
