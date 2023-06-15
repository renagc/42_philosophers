/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/14 16:38:05 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//check if the all chars in array are digit -- done
static int	check_args(char **av)
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

int	ft_atoi_max(const char *str)
{
	int		i;
	long	res;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6 || !check_args(av) || !init_table(av))
		return (ft_printf("Error\nCheck args\n"));
	init_philos();
	if (!init_mutex())
	{
		free_lst();
		return (ft_printf("Error\nCannot init mutexes"));
	}
	if (!init_thread())
	{
		free_lst();
		return (ft_printf("Error\nCannot create threads"));
	}
	if (!join_thread())
	{
		free_lst();
		return (ft_printf("Error\nCannot join threads"));
	}
	if (!destroy_mutex())
	{
		free_lst();
		return (ft_printf("Error\nCannot destroy mutexes"));
	}
	free_lst();
	return (0);
}
