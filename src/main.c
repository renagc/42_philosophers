/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/26 09:37:46 by rgomes-c         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6 || !check_args(av))
		return (ft_printf("Error: check args\n"));
	init_program(av);
	join_thread();
	destroy_mutex();
	return (0);
}
