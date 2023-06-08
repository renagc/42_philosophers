/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:57 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/08 22:10:27 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	write_action(int id, char *str)
{
	pthread_mutex_lock(&table()->write_mutex);
	if (!someone_died() && !philos_are_full())
		ft_printf("%d %d %s\n", get_program_time(), id, str);
	pthread_mutex_unlock(&table()->write_mutex);
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
	pthread_mutex_lock(philo->first);
	write_action(philo->ph_id, "has taken a fork");
	pthread_mutex_lock(philo->second);
	write_action(philo->ph_id, "has taken a fork");
	pthread_mutex_lock(&table()->meal_mutex);
	write_action(philo->ph_id, "is eating");
	philo->last_meal = get_program_time();
	pthread_mutex_unlock(&table()->meal_mutex);
	philo->times_ate += 1;
	f_usleep(table()->t_to_eat);
	pthread_mutex_unlock(philo->first);
	pthread_mutex_unlock(philo->second);
}
