/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:57 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/07 14:11:06 by rgomes-c         ###   ########.fr       */
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
	if (philos_are_alive())
		ft_printf("%d %d %s\n", get_program_time(), id, str);
	if (ft_strncmp(str, "died", 4) != 0)
		pthread_mutex_unlock(&table()->write_mutex);
}

/*
	lock forks form the both sides of philo 
*/
void	lock_forks(t_list *lst)
{
	t_philo	*left;
	t_philo	*right;
	t_philo	*philo;

	philo = (t_philo *)lst->content;
	left = philo;
	right = (t_philo *)lst->next->content;
	if (left->ph_id > right->ph_id || left->ph_id % 2 != 0)
	{
		left = (t_philo *)lst->next->content;
		right = (t_philo *)lst->content;
	}
	pthread_mutex_lock(&left->fork);
	write_action(philo->ph_id, "has taken a fork");
	pthread_mutex_lock(&right->fork);
	write_action(philo->ph_id, "has taken a fork");
}

/*
	unlock forks form the both sides of philo 
*/
void	unlock_forks(t_list *lst)
{
	t_philo	*left;
	t_philo	*right;

	left = (t_philo *)lst->content;
	right = (t_philo *)lst->next->content;
	if (left->ph_id > right->ph_id)
	{
		left = (t_philo *)lst->next->content;
		right = (t_philo *)lst->content;
	}
	pthread_mutex_unlock(&left->fork);
	pthread_mutex_unlock(&right->fork);
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
	write_action(philo->ph_id, "is eating");
	philo->last_meal = get_program_time();
	philo->times_ate += 1;
	pthread_mutex_unlock(&table()->meal_mutex);
	f_usleep(table()->t_to_eat);
	unlock_forks(lst);
}

int	philos_are_full(void)
{
	if (!table()->n_must_eat)
		return (0);
	pthread_mutex_lock(&table()->full_mutex);
	if (table()->all_ate == table()->n_must_eat)
	{
		pthread_mutex_unlock(&table()->full_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table()->full_mutex);
	return (0);
}

void	control_table(void)
{
	t_list	*lst;

	lst = table()->ph_lst;
	while (!philos_are_full())
	{
		pthread_mutex_lock(&table()->meal_mutex);
		if (get_program_time() - ((t_philo *)lst->content)->last_meal
			> table()->t_to_die)
		{
			write_action(((t_philo *)lst->content)->ph_id, "died");
			pthread_mutex_lock(&table()->dead_mutex);
			table()->ph_dead = 1;
			pthread_mutex_unlock(&table()->dead_mutex);
			pthread_mutex_unlock(&table()->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&table()->meal_mutex);
		lst = lst->next;
	}
}
