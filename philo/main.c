/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:48:44 by dayan             #+#    #+#             */
/*   Updated: 2022/08/17 02:48:45 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		error(NBR_ARG);
	if (is_digit(ac, av))
		error(NBR_P);
	data = get_infos(av);
	if (!data)
		error(DATA_0);
	run(data);
	return (0);
}
