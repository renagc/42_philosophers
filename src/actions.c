/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:57 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/08 17:31:32 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
	This function write whats happening using the write_mutex;
	When a philo dies this function only lock the write_mutex;
*/
void	write_action(int id, char *str)
{
	pthread_mutex_lock(&table()->write_mutex);
	if (!someone_died() && !philos_are_full())
		ft_printf("%d %d %s\n", get_program_time(), id, str);
	pthread_mutex_unlock(&table()->write_mutex);
}

/*
	lock forks form the both sides of philo 
*/
void	lock_forks(t_list *lst)
{
	t_philo	*philo;

	philo = (t_philo *)lst->content;
	pthread_mutex_lock(philo->fork1);
	write_action(philo->ph_id, "has taken a fork");
	pthread_mutex_lock(philo->fork2);
	write_action(philo->ph_id, "has taken a fork");
}

/*
	unlock forks form the both sides of philo 
*/
void	unlock_forks(t_list *lst)
{
	t_philo	*philo;

	philo = (t_philo *)lst->content;
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

/*
	This function give food to philo;
	1 step - take forks to eat and write it;
	2 step - lock the meal_mutex and has a good meal, update last time ate;
	3 step - leave forks
*/
void	philo_eats(t_list *lst)
{
	t_philo	*philo;

	philo = (t_philo *)lst->content;
	lock_forks(lst);
	pthread_mutex_lock(&table()->meal_mutex);
	philo->times_ate += 1;
	write_action(philo->ph_id, "is eating");
	philo->last_meal = get_program_time();
	pthread_mutex_unlock(&table()->meal_mutex);
	f_usleep(table()->t_to_eat);
	unlock_forks(lst);
}

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

void	*control_table(void *route)
{
	t_list	*lst;

	(void)route;
	lst = table()->ph_lst;
	while (!philos_are_full())
	{
		if (!philo_is_alive((t_philo *)lst->content))
			break ;
		lst = lst->next;
	}
	return (NULL);
}
