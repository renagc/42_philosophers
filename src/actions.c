/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:57 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/12 15:34:43 by rgomes-c         ###   ########.fr       */
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

void	eat(t_philo *philo)
{
	return ;
}

void	think(t_philo *philo)
{
	return ;
}

void	sleep(t_philo *philo)
{
	return ;
}
