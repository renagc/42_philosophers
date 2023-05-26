/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:54:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/26 11:50:31 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//init all args of the program -- done
int	init_table(char **av)
{
	table()->n_of_ph = ft_atoi(av[1]);
	if (table()->n_of_ph < 1)
		return (0);
	table()->t_to_die = ft_atoi(av[2]);
	table()->t_to_eat = ft_atoi(av[3]);
	table()->t_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table()->n_must_eat = ft_atoi(av[5]);
	else
		table()->n_must_eat = -1;
	table()->start_time = get_time_of_day();
	table()->ph_dead = 0;
	table()->all_ate = 0;
	table()->phs_ate = 0;
	return (1);
}

//creates linked list with all philos
void	init_philos(void)
{
	t_philo	*lst;
	t_philo	*last;
	int		i;

	i = 0;
	lst = 0;
	while (++i <= table()->n_of_ph)
		add_back_philo(&lst, new_philo(i));
	last = last_philo(lst);
	last->next = lst;
	table()->ph_lst = lst;
}

//init all mutexes
int	init_mutex(void)
{
	t_philo	*temp;

	temp = table()->ph_lst;
	while (temp)
	{
		if (pthread_mutex_init(&temp->fork, NULL))
			return (0 * ft_printf("Error initing mutex"));
		if (temp->ph_id == table()->n_of_ph)
			break ;
		temp = temp->next;
	}
	pthread_mutex_init(&table()->meal_mutex, NULL);
	pthread_mutex_init(&table()->dead_mutex, NULL);
	pthread_mutex_init(&table()->write_mutex, NULL);
	pthread_mutex_init(&table()->time_mutex, NULL);
	return (1);
}

//init all philo threads
int	init_thread(void)
{
	t_philo	*temp;

	temp = table()->ph_lst;
	while (temp)
	{
		if (pthread_create(&temp->thread, NULL, routine, temp))
			return (0 * ft_printf("Error creating thread"));
		if (temp->ph_id == table()->n_of_ph)
			break ;
		temp = temp->next;
	}
	if (pthread_create(&table()->thread, NULL, \
		routine_control, table()->ph_lst))
		return (0 * ft_printf("Error creating thread"));
	return (1);
}

int	init_program(char **av)
{
	if (!init_table(av))
		return (0);
	init_philos();
	if (!init_mutex())
		return (0);
	if (!init_thread())
		return (0);
	return (1);
}
