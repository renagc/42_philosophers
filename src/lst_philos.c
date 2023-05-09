/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:40:30 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/09 16:11:35 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// //get the last list
// static t_philo	*last_philo(t_philo *lst)
// {
// 	t_philo	*temp;

// 	if (!lst)
// 		return (lst);
// 	temp = lst;
// 	while (temp->next)
// 		temp = temp->next;
// 	return (temp);
// }

// //adds lst to back
// static void	add_back_philo(t_philo **lst, t_philo *new)
// {
// 	t_philo	*lastlist;

// 	if (!(*lst))
// 		*lst = new;
// 	else
// 	{
// 		lastlist = last_philo(*lst);
// 		lastlist->next = new;
// 	}
// }

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
	t_philo	*philo;
	t_philo	*temp;
	int		i;

	i = 1;
	philo = 0;
	temp = philo;
	while (i <= args->n_of_ph)
	{
		printf("%d", args->n_of_ph);
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (0);
		if (pthread_create(&philo->thread, NULL, test, "ola"))
			return (0);
		pthread_mutex_init(&philo->mutex, NULL);
		philo->ph_id = i;
		philo->t_to_die = args->t_to_die;
		philo->t_to_eat = args->t_to_eat;
		philo->t_to_sleep = args->t_to_sleep;
		philo->n_must_eat = args->n_must_eat;
		i++;
	}
	philo = temp;
	return (philo);
}
