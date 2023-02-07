/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_phil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:06:53 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/07 15:52:53 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void    philosophai(t_data *data)
{
    int     i;

    data->philos = malloc(sizeof(t_philo) * data->nbr_ph);
    i = 0;
    data->death = 0;
    while (i < data->nbr_ph)
    {
        // philos[i] = *(t_philo*) (malloc(sizeof(t_philo)));
        data->philos[i].id = i + 1;
        data->philos[i].data = data;
		data->philos[i].meals = 0;
        // printf("----------- %i ---------\n", i + 1);
		// printf("id: %d\n", data->philos[i].id);
		// printf("data: %p\n", data->philos[i].data);
		// printf("meals: %d\n", data->philos[i].meals);
    	i++;
    }
}

int	meal_amount(t_data *data)
{
	int	i;
	int	a;

	i = 0;
	a = data->nbr_ph;
	while (a--)
	{
		if (data->philos[i].meals >= data->nbr_ph_eat)
			i++;
		else
			return (0);
	}
	return (1);
}
