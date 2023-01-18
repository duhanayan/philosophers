/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:33:17 by dayan             #+#    #+#             */
/*   Updated: 2022/08/17 02:33:18 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// errors
# define NBR_ARG 0
# define NBR_P 1
# define DATA_0 2
# define DATA_1 3
# define DATA_2 4
# define DATA_3 5
# define PHILO_0 6
# define PHILO_1 7

struct	s_data;

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	TAKING,
	DEAD,
}	t_state;

typedef struct s_philos
{
	int				id;
	int				r_fork;
	int				l_fork;
	int				ate;
	long int		last_ate;
	pthread_mutex_t	last_ate_mutex;
	t_state			state;
	struct s_data	*data;
	pthread_t		thread;
}	t_philos;

typedef struct s_data
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	long int		time;
	t_philos		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pen;
}	t_data;

// run
int			run(t_data *data);

// infos
t_data		*get_infos(char **av);

// error
void		error(int x);

// utils
int			ft_atoi(const char *str);
long int	timestamp(void);
void		ft_print(t_philos *philos, t_state state);
void		sleep_sys(int x);
int			is_digit(int ac, char **av);

#endif
