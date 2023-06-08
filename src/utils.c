/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:16:13 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/08 22:12:29 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_time_of_day(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	get_program_time(void)
{
	return (get_time_of_day() - table()->start_time);
}

void	f_usleep(long long n)
{
	long	time;

	time = get_time_of_day();
	while (get_time_of_day() - time < n)
		usleep(table()->n_of_ph);
}

t_table	*table(void)
{
	static t_table	table;

	return (&table);
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
