/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:40:28 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/06/05 00:35:26 by rgomes-c         ###   ########.fr       */
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

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

struct s_table
{
	int					n_of_ph;
	unsigned int		t_to_die;
	unsigned int		t_to_eat;
	unsigned int		t_to_sleep;
	int					n_must_eat;
	long long			all_ate;
	unsigned long long	start_time;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		time_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		fork_check;
	t_list				*ph_lst;
	pthread_t			thread;
	int					ph_dead;
	int					phs_ate;
};

struct s_philo
{
	int					ph_id;
	pthread_t			thread;
	pthread_mutex_t		fork;
	int					fork_in_use;
	unsigned long long	last_meal;
	long long			n_meals;
	int					dead_flag;
};


// -----------------------------  FUNCTIONS --------------------------------- //

//objects
t_table				*table(void);

int					all_ate(void);

//init.c
int					init_table(char **av);
void				init_philos(void);
int					init_mutex(void);
int					init_thread(void);
int					init_program(char **av);

//debug functions
void				ft_printlst(t_list *lst);

//philo.c
void				*routine(void *route);

//lst_utils.c
t_philo				*last_philo(t_philo *lst);
void				add_back_philo(t_philo **lst, t_philo *new);
t_list				*new_philo(int id);

//utils.c
long				get_time_of_day(void);
long				get_program_time(void);
void				f_usleep(long long n);

//thread.c
int					destroy_mutex(void);
int					join_thread(void);

//actions.c
void				f_eat(t_list *lst);
void				f_think(t_philo *philo);
void				f_sleep(t_philo *philo);
void				f_write(t_philo *philo, int action, unsigned long long time);


int					someone_died(void);

//conditions.c
int					check_dead(t_philo *philo);

void				*routine_control(void *route);

#endif
