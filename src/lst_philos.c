/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:40:30 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/12 15:36:14 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//get last philo
static t_philo	*last_philo(t_philo *lst)
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
static void	add_back_philo(t_philo **lst, t_philo *new)
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
static t_philo	*new_philo(t_args *args, int id)
{
	t_philo	*newphilo;

	newphilo = malloc(sizeof(t_philo));
	if (!newphilo)
		return (0);
	newphilo->n_must_eat = args->n_must_eat;
	newphilo->ph_id = id;
	newphilo->t_to_die = args->t_to_die;
	newphilo->t_to_eat = args->t_to_eat;
	newphilo->t_to_sleep = args->t_to_sleep;
	newphilo->next = NULL;
	return (newphilo);
}

void	*routine(void *route)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)route;
	while (are_all_alive(philo))
	{
		eat(philo);
		think(philo);
		sleep(philo);
	}
}

//creates linked list with all philos
t_philo	*init_philos(t_args *args)
{
	t_philo	*lst;
	int		i;

	i = 0;
	lst = 0;
	while (++i <= args->n_of_ph)
		add_back_philo(&lst, new_philo(args, i));
	init_mutex(lst);
	init_thread(lst);
	join_thread(lst);
	return (lst);
}
