/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:40:30 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/26 10:14:49 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//get last philo
t_philo	*last_philo(t_philo *lst)
{
	t_philo	*temp;

	if (!lst)
		return (lst);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

//push back first philo
void	add_back_philo(t_philo **lst, t_philo *new)
{
	t_philo	*lastlist;

	if (!(*lst))
		*lst = new;
	else
	{
		lastlist = last_philo(*lst);
		lastlist->next = new;
	}
}

//creates new_philo
t_philo	*new_philo(int id)
{
	t_philo	*newphilo;

	newphilo = malloc(sizeof(t_philo));
	if (!newphilo)
		return (0);
	newphilo->ph_id = id;
	newphilo->last_meal = 0;
	if (table()->n_must_eat != -1)
		newphilo->n_meals = table()->n_must_eat;
	newphilo->dead_flag = 0;
	newphilo->fork_in_use = 0;
	newphilo->next = NULL;
	return (newphilo);
}
