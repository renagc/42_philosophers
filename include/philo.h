/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:40:28 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/16 21:58:18 by rgomes-c         ###   ########.fr       */
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

typedef struct s_philo
{
	int					ph_id;
	pthread_t			thread;
	int					is_alive;
	unsigned long long	ate_time;
	pthread_mutex_t		fork;
	struct s_philo		*next;
}t_philo;

typedef struct s_table
{
	int					n_of_ph;
	unsigned int		t_to_die;
	unsigned int		t_to_eat;
	unsigned int		t_to_sleep;
	int					n_must_eat;
	t_philo				*philos;
	unsigned long long	start_time;
}t_table;

// -----------------------------  FUNCTIONS --------------------------------- //

//debug functions
void				ft_printlst(t_philo *philos);

//philo.c
void				init_philos(t_table *table);
void				*routine(void *route);

//utils.c
unsigned long long	get_time(void);

//thread.c
int					init_mutex(t_table *table);
int					init_thread(t_table *table);
int					join_thread(t_table *table);

//actions.c
int					are_all_alive(t_philo *philos);
void				f_eat(t_philo *philo);
void				f_think(t_philo *philo);
void				f_sleep(t_philo *philo);

#endif
