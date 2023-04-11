/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/04/04 11:45:58 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int ft_is_digit_array(char **av)
{
	int 	i;
	int 	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while(av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (0);
	}
	return (1);
}

static int	ft_init_args(t_args *args, char **av)
{
	if (!ft_is_digit_array(av))
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

int	main(int ac, char **av)
{
	t_args	args;

	if (ac < 5 || ac > 6 || !ft_init_args(&args, av))
		return(ft_printf("Error: check args\n"));
	return (0);
}
