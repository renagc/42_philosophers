/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:40:30 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/18 16:25:54 by rgomes-c         ###   ########.fr       */
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
static t_philo	*new_philo(int id, t_table *table)
{
	t_philo	*newphilo;

	newphilo = malloc(sizeof(t_philo));
	if (!newphilo)
		return (0);
	newphilo->ph_id = id;
	newphilo->last_time_ate = get_time();
	newphilo->table_data = table;
	newphilo->next = NULL;
	return (newphilo);
}

void	*routine(void *route)
{
	t_philo	*philo;

	philo = (t_philo *)route;
	while (philo->table_data->dead_flag != 1)
	{
		if (philo->ph_id % 2 == 0)
			usleep(500);
		f_eat(philo);
		f_sleep(philo);
		f_think(philo);
	}
	return (NULL);
}

//creates linked list with all philos
t_philo	*init_philos(t_table *table)
{
	t_philo	*lst;
	t_philo	*last;
	int		i;

	i = 0;
	lst = 0;
	while (++i <= table->n_of_ph)
		add_back_philo(&lst, new_philo(i, table));
	last = last_philo(lst);
	last->next = lst;
	table->ph_head_lst = lst;
	table->start_time = get_time();
	return (lst);
}
