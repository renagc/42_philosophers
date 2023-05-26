/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/26 12:08:32 by rgomes-c         ###   ########.fr       */
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

void	free_lst(void)
{
	t_philo	*first;
	t_philo	*next;
	t_philo	*last;

	first = table()->ph_lst;
	last = table()->ph_lst;
	while (last->ph_id != table()->n_of_ph)
		last = last->next;
	last->next = NULL;
	next = first;
	while (next)
	{
		next = first->next;
		free(first);
		first = next;
	}
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6 || !check_args(av))
		return (ft_printf("Error: check args\n"));
	if (!init_program(av))
	{
		ft_printf("Error\nMust have at least 1 Philo\n");
		return (0);
	}
	join_thread();
	destroy_mutex();
	free_lst();
	return (0);
}
