/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:00:08 by dayan             #+#    #+#             */
/*   Updated: 2022/08/17 03:00:09 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			res;
	int			sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' '
		|| str[i] == '\t'
		|| str[i] == '\n'
		|| str[i] == '\v'
		|| str[i] == '\f'
		|| str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	return (res * sign);
}

int	is_digit(int ac, char **av)
{
	int	x;
	int	j;

	x = 0;
	while (++x < ac)
	{
		j = -1;
		while (av[x][++j] != '\0')
			if (av[x][j] < '0' || av[x][j] > '9')
				return (1);
	}
	return (0);
}

long int	timestamp(void)
{
	struct timeval	current;
	long int		time;

	gettimeofday(&current, NULL);
	time = current.tv_sec * 1000;
	time += current.tv_usec / 1000;
	return (time);
}

void	ft_print(t_philos *philos, t_state state)
{
	char	*str;

	str = NULL;
	if (state == EATING)
		str = "eating";
	else if (state == SLEEPING)
		str = "sleeping";
	else if (state == THINKING)
		str = "thinking";
	else if (state == TAKING)
		str = "has taken a fork";
	pthread_mutex_lock(&philos->data->pen);
	printf("%ldms %d %s\n", timestamp() - philos->data->time, philos->id, str);
	pthread_mutex_unlock(&philos->data->pen);
}

void	sleep_sys(int x)
{
	long int	t;

	t = timestamp() + x;
	while (timestamp() < t)
		usleep(10);
}
