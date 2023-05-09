/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/07 10:58:31 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//check if the all chars in array are digit -- done
static int	is_digit_array(char **av)
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

//init all args of the program -- done
static int	init_args(t_args *args, char **av)
{
	if (!is_digit_array(av))
		return (0);
	args->n_of_ph = ft_atoi(av[1]);
	if (args->n_of_ph < 1)
		return (0);
	args->t_to_die = ft_atoi(av[2]);
	args->t_to_eat = ft_atoi(av[3]);
	args->t_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->n_must_eat = ft_atoi(av[5]);
	else
		args->n_must_eat = -1;
	return (1);
}

t_philo	*philonew(t_args *args)
{
	t_philo	*newphilo;

	newphilo = malloc(sizeof(t_philo));
	if (!newphilo)
		return (0);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (0);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastlist;

	if (!(*lst))
		*lst = new;
	else
	{
		lastlist = ft_lstlast(*lst);
		lastlist -> next = new;
	}
}

t_philo	init_philos(t_args *args)
{
	t_philo	*philo;
	t_philo	*list;
	int		i;

	i = 1;
	while (i <= args->n_of_ph)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
		if (pthread_create(philo.thread, NULL, othername, &teste))
			return (ft_printf("Error: pthread\n"));
		pthread_mutex_init(&philo.mutex, NULL);
	}
}

int	main(int ac, char **av)
{
	t_args			args;
	pthread_t		t1;
	pthread_t		t2;

	pthread_mutex_init(&teste.mutex, NULL);
	if (ac < 5 || ac > 6 || !init_args(&args, av))
		return (ft_printf("Error: check args\n"));
	if (pthread_create(&t1, NULL, othername, &teste))
		return (ft_printf("Error: pthread\n"));
	if (pthread_create(&t2, NULL, othername, &teste))
		return (ft_printf("Error: pthread\n"));
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&teste.mutex);
	ft_printf("%d\n", teste.i);
	return (0);
}
