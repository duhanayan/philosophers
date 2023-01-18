/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:06:46 by dayan             #+#    #+#             */
/*   Updated: 2022/08/17 04:06:47 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dinner(t_philos *philos, int l, int r)
{
	pthread_mutex_lock(&philos->data->forks[l]);
	philos->state = TAKING;
	ft_print(philos, philos->state);
	pthread_mutex_lock(&philos->data->forks[r]);
	philos->state = TAKING;
	ft_print(philos, philos->state);
	philos->state = EATING;
	ft_print(philos, philos->state);
	sleep_sys(philos->data->t_eat);
	pthread_mutex_lock(&philos->last_ate_mutex);
	philos->last_ate = timestamp();
	pthread_mutex_lock(&philos->last_ate_mutex);
	philos->ate++;
	pthread_mutex_unlock(&philos->data->forks[l]);
	pthread_mutex_unlock(&philos->data->forks[r]);
	philos->state = SLEEPING;
	ft_print(philos, philos->state);
	sleep_sys(philos->data->t_sleep);
	philos->state = THINKING;
	ft_print(philos, philos->state);
}

void	*begin(void *name)
{
	t_philos	*philos;

	philos = (t_philos *) name;
	if (philos->id % 2 != 0)
		usleep(150);
	while (1)
		start_dinner(philos, philos->l_fork, philos->r_fork);
	return (NULL);
}

int	check_if_ate_enough(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->n_philos)
		if (data->philos[x].ate < data->must_eat)
			return (0);
	return (1);
}

int	check_if_died(t_data *data)
{
	int	x;

	while (1)
	{
		x = -1;
		while (++x < data->n_philos)
		{
			pthread_mutex_lock(&data->philos->last_ate_mutex);
			if (timestamp() - data->philos[x].last_ate >= data->t_die)
			{
				pthread_mutex_lock(&data->pen);
				printf("%ldms %d %s", timestamp() - data->time,
					data->philos[x].id, "has died!\n");
				return (1);
			}
			pthread_mutex_unlock(&data->philos->last_ate_mutex);
			if (data->must_eat > 0 && check_if_ate_enough(data))
				return (1);
		}
	}
	return (0);
}

int	run(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->n_philos)
		pthread_mutex_init(&data->forks[x], NULL);
	pthread_mutex_init(&data->pen, NULL);
	data->time = timestamp();
	x = -1;
	while (++x < data->n_philos)
	{
		data->philos[x].last_ate = timestamp();
		pthread_create(&data->philos[x].thread, NULL,
			begin, (void *) &data->philos[x]);
	}
	if (check_if_died(data))
		return (1);
	return (0);
}
