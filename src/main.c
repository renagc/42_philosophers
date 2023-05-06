/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:45:55 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/05/07 00:28:43 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_is_digit_array(char **av)
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

static int	ft_init_args(t_args *args, char **av)
{
	if (!ft_is_digit_array(av))
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

void	*othername(void *teste)
{
	t_teste			*try;
	int				a;

	a = -1;
	try = (struct s_teste *)teste;
	pthread_mutex_lock(&try->mutex);
	while (++a < 10000)
	{
		try->i += 1;
	}
	pthread_mutex_unlock(&try->mutex);
	return (NULL);
}

//list of philosophers
t_list	*init_philos(t_args *args)
{
	t_list	*temp;
	t_list	*ph_list;
	t_philo	*ph;
	int		i;

	ph = 0;
	temp = ft_lstnew((t_philo *)ph);
	ph_list = temp;
	i = 0;
	while (i < args->n_of_ph)
	{
		ph = (t_philo *)temp->content;
		ph->ph_id = i;
		ft_lstadd_back(&temp, ft_lstnew(ph));
		temp = temp->next;
	}
	return (ph_list);
}

int	main(int ac, char **av)
{
	t_args			args;
	pthread_t		t1;
	pthread_t		t2;
	t_teste			teste;

	teste.i = 0;
	pthread_mutex_init(&teste.mutex, NULL);
	if (ac < 5 || ac > 6 || !ft_init_args(&args, av))
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
