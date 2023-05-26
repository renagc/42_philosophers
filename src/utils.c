/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:16:13 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/23 16:59:32 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned long long	get_time_of_day(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

unsigned long long	get_program_time(void)
{
	return (get_time_of_day() - table()->start_time);
}

void	f_usleep(long long n)
{
	unsigned long long	time;

	time = get_time_of_day() + n;
	while (get_time_of_day() < time)
		usleep(10);
}
