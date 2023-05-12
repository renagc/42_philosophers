/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:40:30 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/09 16:30:00 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//get the last list
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

//adds lst to back
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

//new_philo
static t_philo	*new_philo(t_args *args, int id)
{
	t_philo	*newphilo;

	newphilo = malloc(sizeof(t_list));
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

void	*test(void *s)
{
	ft_printf("%s\n", (char *)s);
	return (NULL);
}

void	destroy_mutexs(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		pthread_mutex_destroy(&temp->mutex);
		temp = temp->next;
	}
}

void	join_threads(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
	}
}

//creates linked list with all philos
t_philo	*init_philos(t_args *args)
{
	t_philo	*lst;
	int		i;

	i = 1;
	lst = 0;
	while (i <= args->n_of_ph)
	{
		//if (pthread_create(&temp->thread, NULL, test, "ola"))
		//	return (0);
		//pthread_mutex_init(&temp->mutex, NULL);
		add_back_philo(&lst, new_philo(args, i));
		i++;
	}
	return (lst);
}
