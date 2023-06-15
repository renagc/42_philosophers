/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:54:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/15 09:27:46 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//init all args of the program -- done
int	init_table(char **av)
{
	table()->n_of_ph = ft_atoi_max(av[1]);
	table()->t_to_die = ft_atoi_max(av[2]);
	table()->t_to_eat = ft_atoi_max(av[3]);
	table()->t_to_sleep = ft_atoi_max(av[4]);
	if (av[5])
	{
		table()->n_must_eat = ft_atoi_max(av[5]);
		if (table()->n_must_eat <= 0)
			return (0);
	}
	if (table()->n_of_ph <= 0 || table()->t_to_die <= 0
		|| table()->t_to_eat <= 0 || table()->t_to_sleep <= 0)
		return (0);
	table()->all_ate = 0;
	table()->ph_dead = 0;
	return (1);
}

t_list	*ft_new(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (0);
	newlist->content = (t_philo *)content;
	newlist->next = NULL;
	return (newlist);
}

//creates new_philo
t_list	*new_philo(int id)
{
	t_philo	*newphilo;

	newphilo = (t_philo *)malloc(sizeof(t_philo));
	if (!newphilo)
		return (0);
	newphilo->ph_id = id;
	newphilo->last_meal = 0;
	newphilo->times_ate = 0;
	return (ft_new(newphilo));
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
