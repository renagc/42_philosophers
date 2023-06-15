/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:40:28 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/14 16:40:56 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// ------------------------------- INCLUDES --------------------------------- //

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include "../lib/libft/include/libft.h"

// -------------------------------- MACROS ---------------------------------- //

// ------------------------------- STRUCTS ---------------------------------- //

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

struct s_table
{
	int					n_of_ph;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					n_must_eat;
	long long			all_ate;
	long				start_time;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		full_mutex;
	pthread_mutex_t		dead_mutex;
	t_list				*ph_lst;
	pthread_t			thread;
	int					ph_dead;
};

struct s_philo
{
	int					ph_id;
	pthread_t			thread;
	pthread_mutex_t		fork;
	pthread_mutex_t		*first;
	pthread_mutex_t		*second;
	long				last_meal;
	int					times_ate;
};

// -----------------------------  FUNCTIONS --------------------------------- //

//init.c
int					init_table(char **av);
void				init_philos(void);

//mutex.c
int					init_mutex(void);
void				philo_select_forks(void);
int					destroy_mutex(void);

//thread.c
int					init_thread(void);
int					join_thread(void);

//actions.c
void				write_action(int id, char *str);
void				philo_eats(t_list *lst);

//conditions.c
int					philo_is_alive(t_philo *philo);
int					philo_is_full(t_philo *philo);
int					someone_died(void);
int					philos_are_full(void);

//utils.c
long				get_time_of_day(void);
long				get_program_time(void);
void				f_usleep(long long n);
t_table				*table(void);
void				free_lst(void);

//main.c
int					ft_atoi_max(const char *str);

#endif
