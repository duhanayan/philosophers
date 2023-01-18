/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:51:37 by dayan             #+#    #+#             */
/*   Updated: 2022/08/17 02:51:38 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(int x)
{
	if (x == 0)
		printf("Error: Number of arguments must be 5 or 6.\n");
	else if (x == 1)
		printf("Error: Arguments must be positive numbers.\n");
	else if (x == 2)
		printf("Eror: Failed to allocate for 'data'.\n");
	else if (x == 3)
		printf("Eror: Failed to allocate for 'data'. *\n");
	else if (x == 4)
		printf("Eror: [number_of_times_each_philosopher_must_eat]\
can not be 0.\n");
	else if (x == 5)
		printf("Eror: time_to_die, time_to_eat and time_to_sleep\
can not be 0.\n");
	else if (x == 6)
		printf("Eror: Failed to allocate for 'data->philos'.\n");
	else if (x == 7)
		printf("Error: Failed to allocate for 'data->philos'. *\n");
	exit(1);
}
