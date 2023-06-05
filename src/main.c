/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/05 00:24:40 by rgomes-c         ###   ########.fr       */
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

//free philos list
void	free_lst(void)
{
	t_list	*first;
	t_list	*next;
	t_list	*last;
	int		i;

	first = table()->ph_lst;
	last = table()->ph_lst;
	i = 0;
	while (++i <= table()->n_of_ph)
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
		return (ft_printf("Error\nCheck args\n"));
	if (!init_table(av))
		return (ft_printf("Error\nMust have at least 1 Philo\n"));
	init_philos();
	if (!init_mutex())
		return (ft_printf("Error\nCannot init mutexes"));
	if (!init_thread())
		return (ft_printf("Error\nCannot create threads"));
	if (!join_thread())
		return (ft_printf("Error\nCannot join threads"));
	destroy_mutex();
	free_lst();
	return (0);
}
