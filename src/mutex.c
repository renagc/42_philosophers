/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:55:09 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/08 22:17:58 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(void)
{
	t_list	*temp;
	int		i;

	temp = table()->ph_lst;
	i = -1;
	while (++i < table()->n_of_ph)
	{
		if (pthread_mutex_init(&((t_philo *)temp->content)->fork, NULL))
			return (0);
		temp = temp->next;
	}
	philo_select_forks();
	if (pthread_mutex_init(&table()->meal_mutex, NULL))
		return (0);
	if (pthread_mutex_init(&table()->dead_mutex, NULL))
		return (0);
	if (pthread_mutex_init(&table()->write_mutex, NULL))
		return (0);
	if (pthread_mutex_init(&table()->full_mutex, NULL))
		return (0);
	return (1);
}

void	philo_select_forks(void)
{
	t_list	*lst;
	t_philo	*philo1;
	t_philo	*philo2;
	int		i;

	lst = table()->ph_lst;
	i = -1;
	while (++i < table()->n_of_ph)
	{
		philo1 = (t_philo *)lst->content;
		philo2 = (t_philo *)lst->next->content;
		if (i % 2 != 0)
		{
			philo1->first = &philo1->fork;
			philo1->second = &philo2->fork;
		}
		else
		{
			philo1->first = &philo2->fork;
			philo1->second = &philo1->fork;
		}
		lst = lst->next;
	}
}

int	destroy_mutex(void)
{
	t_list	*temp;
	int		i;

	temp = table()->ph_lst;
	i = -1;
	while (++i < table()->n_of_ph)
	{
		if (pthread_mutex_destroy(&((t_philo *)temp->content)->fork))
			return (0);
		temp = temp->next;
	}
	if (pthread_mutex_destroy(&table()->meal_mutex))
		return (0);
	if (pthread_mutex_destroy(&table()->dead_mutex))
		return (0);
	if (pthread_mutex_destroy(&table()->write_mutex))
		return (0);
	if (pthread_mutex_destroy(&table()->full_mutex))
		return (0);
	return (1);
}
