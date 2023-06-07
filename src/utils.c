/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:16:13 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/07 14:16:22 by rgomes-c         ###   ########.fr       */
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
