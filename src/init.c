/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:54:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/07 14:11:35 by rgomes-c         ###   ########.fr       */
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
	table()->start_time = get_time_of_day();
	table()->all_ate = 0;
	table()->ph_dead = 0;
	return (1);
}

//creates new_philo
t_list	*new_philo(int id)
{
	t_philo	*newphilo;

	newphilo = malloc(sizeof(t_philo));
	if (!newphilo)
		return (0);
	newphilo->ph_id = id;
	newphilo->last_meal = 0;
	newphilo->dead_flag = 0;
	newphilo->fork_in_use = 0;
	newphilo->times_ate = 0;
	return (ft_lstnew((t_philo *)newphilo));
}

//creates linked list with all philos -- done
void	init_philos(void)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = 0;
	while (++i <= table()->n_of_ph)
		ft_lstadd_back(&lst, new_philo(i));
	ft_lstlast(lst)->next = lst;
	table()->ph_lst = lst;
}

//init all mutexes -- done
int	init_mutex(void)
{
	t_list	*temp;
	int		i;

	temp = table()->ph_lst;
	i = 0;
	while (++i <= table()->n_of_ph)
	{
		if (pthread_mutex_init(&((t_philo *)temp->content)->fork, NULL))
			return (0);
		temp = temp->next;
	}
	pthread_mutex_init(&table()->fork_mutex, NULL);
	pthread_mutex_init(&table()->meal_mutex, NULL);
	pthread_mutex_init(&table()->dead_mutex, NULL);
	pthread_mutex_init(&table()->write_mutex, NULL);
	pthread_mutex_init(&table()->time_mutex, NULL);
	pthread_mutex_init(&table()->full_mutex, NULL);
	return (1);
}

//init all philo threads -- done
int	init_thread(void)
{
	t_list	*temp;
	int		i;

	temp = table()->ph_lst;
	i = 0;
	while (++i <= table()->n_of_ph)
	{
		if (pthread_create(&((t_philo *)temp->content)->thread,
				NULL, routine, temp))
			return (0);
		temp = temp->next;
	}
	control_table();
	if (table()->ph_dead == 1)
		pthread_mutex_unlock(&table()->write_mutex);
	return (1);
}
