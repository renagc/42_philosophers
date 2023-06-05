/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:03 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/05 00:36:29 by rgomes-c         ###   ########.fr       */
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
	pthread_mutex_destroy(&table()->meal_mutex);
	pthread_mutex_destroy(&table()->dead_mutex);
	pthread_mutex_destroy(&table()->write_mutex);
	pthread_mutex_destroy(&table()->time_mutex);
	pthread_mutex_destroy(&table()->fork_check);
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
	if (pthread_join(table()->thread, NULL))
		return (0);
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
	t_list	*temp;

	temp = (t_list *)route;
	if (one_philo((t_philo *)temp->content))
		return (NULL);
	while (!someone_died())
	{
		f_eat(temp);
		if (((t_philo *)temp->content)->n_meals == 0)
			break ;
		if (!someone_died())
			f_write(((t_philo *)temp->content), SLEEP, get_program_time());
		if (!someone_died())
			f_usleep(table()->t_to_sleep);
		if (!someone_died())
			f_write(((t_philo *)temp->content), THINK, get_program_time());
	}
	return (NULL);
}

void	*routine_control(void *route)
{
	t_list				*lst;
	t_philo				*philo;

	lst = (t_list *)route;
	if (table()->n_of_ph == 1)
		return (NULL);
	while (lst)
	{
		philo = (t_philo *)lst->content;
		pthread_mutex_lock(&table()->meal_mutex);
		if (table()->phs_ate == table()->n_of_ph)
		{
			pthread_mutex_unlock(&table()->meal_mutex);
			return (NULL);
		}
		if ((get_program_time() - philo->last_meal) > table()->t_to_die && philo->last_meal)
		{
			pthread_mutex_lock(&table()->dead_mutex);
			table()->ph_dead = 1;
			pthread_mutex_unlock(&table()->dead_mutex);
			pthread_mutex_lock(&table()->write_mutex);
			ft_printf("%d %d died\n", get_program_time(), philo->ph_id);
			pthread_mutex_unlock(&table()->write_mutex);
			pthread_mutex_unlock(&table()->meal_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&table()->meal_mutex);
		lst = lst->next;
	}
	return (NULL);
}
