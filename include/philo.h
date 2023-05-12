/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:40:28 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/12 15:35:00 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// ------------------------------- INCLUDES --------------------------------- //

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "../lib/libft/include/libft.h"

// -------------------------------- MACROS ---------------------------------- //

// ------------------------------- STRUCTS ---------------------------------- //

typedef struct s_args
{
	int				n_of_ph;
	unsigned int	t_to_die;
	unsigned int	t_to_eat;
	unsigned int	t_to_sleep;
	int				n_must_eat;
}t_args;

typedef struct s_philo
{
	int				ph_id;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				is_alive;
	unsigned int	t_to_die;
	unsigned int	t_to_eat;
	unsigned int	t_to_sleep;
	int				n_must_eat;
	struct s_philo	*next;
}t_philo;

// -----------------------------  FUNCTIONS --------------------------------- //

//debug functions
void				ft_printlst(t_philo *philos);

//philo.c
t_philo				*init_philos(t_args *args);
void				*routine(void *route);

//utils.c
unsigned long long	get_time(void);

//thread.c
int					init_mutex(t_philo *philos);
int					init_thread(t_philo	*philos);
int					join_thread(t_philo *philos);

//actions.c
int					are_all_alive(t_philo *philos);
void				eat(t_philo *philo);
void				think(t_philo *philo);
void				sleep(t_philo *philo);

#endif
