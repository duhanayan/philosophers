/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:46:35 by dayan             #+#    #+#             */
/*   Updated: 2022/08/17 03:46:36 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*get_philos(t_data *data)
{
	t_philos	*philos;
	int			x;

	philos = malloc(sizeof(t_philos) * data->n_philos);
	if (!philos)
		error(PHILO_1);
	x = -1;
	while (++x < data->n_philos)
	{
		philos[x].id = x + 1;
		philos[x].r_fork = x;
		philos[x].l_fork = x - 1;
		if (philos[x].l_fork == -1)
			philos[x].l_fork = data->n_philos - 1;
		philos[x].ate = 0;
		philos[x].last_ate = 0;
		philos[x].state = THINKING;
		philos[x].data = data;
	}
	return (philos);
}

t_data	*get_infos(char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		data->must_eat = ft_atoi(av[5]);
		if (data->must_eat == 0)
			error(DATA_1);
	}
	else
		data->must_eat = -1;
	if (data->t_die == 0 || data->t_eat == 0 || data->t_sleep == 0)
		error(DATA_2);
	data->time = 0;
	data->philos = get_philos(data);
	if (!data->philos)
		error(PHILO_0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (NULL);
	return (data);
}
