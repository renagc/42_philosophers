/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:40:28 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/18 16:23:15 by rgomes-c         ###   ########.fr       */
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

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEAD 5

// ------------------------------- STRUCTS ---------------------------------- //

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					n_of_ph;
	unsigned int		t_to_die;
	unsigned int		t_to_eat;
	unsigned int		t_to_sleep;
	int					n_must_eat;
	unsigned long long	start_time;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		time_mutex;
	pthread_mutex_t		dead_mutex;
	int					dead_flag;
	t_philo				*ph_head_lst;
}t_table;

struct s_philo
{
	int					ph_id;
	pthread_t			thread;
	unsigned long long	last_time_ate;
	pthread_mutex_t		fork;
	t_table				*table_data;
	t_philo				*next;
};


// -----------------------------  FUNCTIONS --------------------------------- //

//debug functions
void				ft_printlst(t_philo *philos);

//philo.c
t_philo				*init_philos(t_table *table);
void				*routine(void *route);

//utils.c
unsigned long long	get_time(void);
unsigned long long	get_exec_time(unsigned long long start_time);

//thread.c
int					init_mutex(t_philo *philos);
int					destroy_mutex(t_philo *philos);
int					init_thread(t_philo *philos);
int					join_thread(t_philo *philos);

//actions.c
void				f_eat(t_philo *philo);
void				f_think(t_philo *philo);
void				f_sleep(t_philo *philo);
void				f_write(t_philo *philo, int action, unsigned long long time);

//conditions.c
int					f_all_alive(t_philo *philo);
int					check_dead(t_philo *philos);

#endif
