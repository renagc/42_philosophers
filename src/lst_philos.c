/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:40:30 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/16 22:06:41 by rgomes-c         ###   ########.fr       */
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
static t_philo	*new_philo(int id)
{
	t_philo	*newphilo;

	newphilo = malloc(sizeof(t_philo));
	if (!newphilo)
		return (0);
	newphilo->ph_id = id;
	newphilo->ate_time = 0;
	newphilo->next = NULL;
	return (newphilo);
}

void	*routine(void *route)
{
	t_table	*table;

	table = (t_table *)route;
	while (are_all_alive(table->philos))
	{
		f_eat(table->philos);
		f_think(table->philos);
		f_sleep(table->philos);
	}
	return (NULL);
}

//creates linked list with all philos
void	init_philos(t_table *table)
{
	t_philo	*lst;
	int		i;

	i = 0;
	lst = 0;
	while (++i <= table->n_of_ph)
		add_back_philo(&lst, new_philo(i));
	table->philos = lst;
	init_mutex(table);
	table->start_time = get_time();
	init_thread(table);
	join_thread(table);
}
