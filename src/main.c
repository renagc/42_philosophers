/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/18 16:26:19 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//check if the all chars in array are digit -- done
static int	is_digit_array(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (0);
	}
	return (1);
}

//init all args of the program -- done
static int	init_table(t_table *table, char **av)
{
	if (!is_digit_array(av))
		return (0);
	table->n_of_ph = ft_atoi(av[1]);
	if (table->n_of_ph < 1)
		return (0);
	table->t_to_die = ft_atoi(av[2]);
	table->t_to_eat = ft_atoi(av[3]);
	table->t_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->n_must_eat = ft_atoi(av[5]);
	else
		table->n_must_eat = -1;
	return (1);
}

int	main(int ac, char **av)
{
	t_table	table;
	t_philo	*philos;

	if (ac < 5 || ac > 6 || !init_table(&table, av))
		return (ft_printf("Error: check args\n"));
	philos = init_philos(&table);
	init_mutex(philos);
	init_thread(philos);
	if (!check_dead(philos))
		join_thread(philos);
	destroy_mutex(philos);
	return (0);
}
