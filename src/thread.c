/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:03 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/08 22:23:59 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *route);
void	*control_table(void *route);

/*
	Init thread for each philo and one thread to control;
*/
int	init_thread(void)
{
	t_list	*temp;
	int		i;

	temp = table()->ph_lst;
	i = -1;
	table()->start_time = get_time_of_day();
	while (++i < table()->n_of_ph)
	{
		if (pthread_create(&((t_philo *)temp->content)->thread,
				NULL, routine, temp))
			return (0);
		temp = temp->next;
	}
	if (pthread_create(&table()->thread, NULL, control_table, NULL))
		return (0);
	return (1);
}

/*
	Routine for each philo thread;
*/
void	*routine(void *route)
{
	t_list	*temp;

	temp = (t_list *)route;
	if (table()->n_of_ph == 1)
	{
		write_action(((t_philo *)temp->content)->ph_id, "has taken a fork");
		return (NULL);
	}
	if (((t_philo *)temp->content)->ph_id % 2 == 0)
		usleep(200);
	while (!someone_died())
	{
		philo_eats(temp);
		if (philo_is_full((t_philo *)temp->content))
			break ;
		write_action(((t_philo *)temp->content)->ph_id, "is sleeping");
		if (someone_died())
			break ;
		f_usleep(table()->t_to_sleep);
		if (someone_died())
			break ;
		write_action(((t_philo *)temp->content)->ph_id, "is thinking");
	}
	return (NULL);
}

/*
	Control table for verifying ;
*/
void	*control_table(void *route)
{
	t_list	*lst;

	(void)route;
	lst = table()->ph_lst;
	while (!philos_are_full())
	{
		if (!philo_is_alive((t_philo *)lst->content))
			break ;
		lst = lst->next;
	}
	return (NULL);
}

int	join_thread(void)
{
	t_list	*temp;
	int		i;

	temp = table()->ph_lst;
	i = -1;
	while (++i < table()->n_of_ph)
	{
		if (pthread_join(((t_philo *)temp->content)->thread, NULL))
			return (0);
		temp = temp->next;
	}
	if (pthread_join(table()->thread, NULL))
		return (0);
	return (1);
}
