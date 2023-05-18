/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/16 15:56:28 by rgomes-c         ###   ########.fr       */
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

//free all philos
static void	free_lst(t_philo *lst)
{
	t_philo	*temp;

	temp = lst;
	while (lst)
	{
		lst = lst->next;
		free(temp);
		temp = lst;
	}
}

int	main(int ac, char **av)
{
	t_table table;

	if (ac < 5 || ac > 6 || !init_table(&table, av))
		return (ft_printf("Error: check args\n"));
	init_philos(&table);
	free_lst(table.philos);
	return (0);
}
