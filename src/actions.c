/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:57 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/05 00:34:56 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_write(t_philo *philo, int action, unsigned long long time)
{
	char	*str;

	str = NULL;
	if (action == FORK)
		str = "has taken a fork";
	else if (action == EAT && !someone_died())
		str = "is eating";
	else if (action == SLEEP && !someone_died())
		str = "is sleeping";
	else if (action == THINK && !someone_died())
		str = "is thinking";
	else if (action == DEAD)
		str = "died";
	if (someone_died())
		return ;
	pthread_mutex_lock(&table()->write_mutex);
	if (someone_died())
	{
		pthread_mutex_unlock(&table()->write_mutex);
		return ;
	}
	ft_printf("%d %d %s\n", time, philo->ph_id, str);
	pthread_mutex_unlock(&table()->write_mutex);
}

void	lock_forks(t_list *lst)
{
	if (((t_philo *)lst->content)->ph_id % 2 == 0)
	{
		pthread_mutex_lock(&((t_philo *)lst->content)->fork);
		pthread_mutex_lock(&((t_philo *)lst->next->content)->fork);
	}
	else
	{
		pthread_mutex_lock(&((t_philo *)lst->next->content)->fork);
		pthread_mutex_lock(&((t_philo *)lst->content)->fork);
	}
}

void	unlock_forks(t_list *lst)
{
	if (((t_philo *)lst->content)->ph_id % 2 == 0)
	{
		pthread_mutex_unlock(&((t_philo *)lst->content)->fork);
		pthread_mutex_unlock(&((t_philo *)lst->next->content)->fork);
	}
	else
	{
		pthread_mutex_unlock(&((t_philo *)lst->next->content)->fork);
		pthread_mutex_unlock(&((t_philo *)lst->content)->fork);
	}
}

void	f_eat(t_list *lst)
{
	if (someone_died())
		return ;
	lock_forks(lst);
	if (someone_died())
	{
		unlock_forks(lst);
		return ;
	}
	f_write((t_philo *)lst->content, FORK, get_program_time());
	if (someone_died())
	{
		unlock_forks(lst);
		return ;
	}
	f_write((t_philo *)lst->content, FORK, get_program_time());
	if (someone_died())
	{
		unlock_forks(lst);
		return ;
	}
	f_write((t_philo *)lst->content, EAT, get_program_time());
	pthread_mutex_lock(&table()->meal_mutex);
	((t_philo *)lst->content)->last_meal = get_program_time();
	table()->all_ate += 1;
	pthread_mutex_unlock(&table()->meal_mutex);
	f_usleep(table()->t_to_eat);
	unlock_forks(lst);
	((t_philo *)lst->content)->n_meals -= 1;
	if (((t_philo *)lst->content)->n_meals == 0)
	{
		pthread_mutex_lock(&table()->meal_mutex);
		table()->phs_ate += 1;
		pthread_mutex_unlock(&table()->meal_mutex);
	}
}
