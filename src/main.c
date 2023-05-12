/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/12 14:38:58 by rgomes-c         ###   ########.fr       */
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
static int	init_args(t_args *args, char **av)
{
	if (!is_digit_array(av))
		return (0);
	args->n_of_ph = ft_atoi(av[1]);
	if (args->n_of_ph < 1)
		return (0);
	args->t_to_die = ft_atoi(av[2]);
	args->t_to_eat = ft_atoi(av[3]);
	args->t_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->n_must_eat = ft_atoi(av[5]);
	else
		args->n_must_eat = -1;
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
	t_args	args;
	t_philo	*philos;

	if (ac < 5 || ac > 6 || !init_args(&args, av))
		return (ft_printf("Error: check args\n"));
	philos = init_philos(&args);
	free_lst(philos);
	return (0);
}
