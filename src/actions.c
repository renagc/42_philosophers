/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:57 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/16 16:38:12 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	are_all_alive(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		if (!temp->is_alive)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	f_eat(t_philo *philo)
{
	(void)philo;
	return ;
}

void	f_think(t_philo *philo)
{
	(void)philo;
	return ;
}

void	f_sleep(t_philo *philo)
{
	(void)philo;
	return ;
}
