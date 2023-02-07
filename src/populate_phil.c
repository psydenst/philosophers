/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_phil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:06:53 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/07 11:54:02 by psydenst         ###   ########.fr       */
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

// void    monitoring(t_data *data)
// {
//     int i;
//     long long time;
//     long long now;
//     i = 0;
//     // while(1)
//     // {
//     //     i = 0;
//     //     while (i < data->nbr_ph)
//     //     {
//     //         printf("last_meal[%i]: %lli\n", i + 1, data->philos[i].last_meal);
//     //         usleep(50000);
//     //         i++;
//     //     }
//     //     usleep(50000);
//     // }
//     while (1)
//     {
//         now = ft_time_in_mls();
//         if (i > data->nbr_ph)
//             i = 0;
//         time = *(long long*) (now - data->philos[i].last_meal);
//         if (time > data->time_to_die)
//         {
//             to_die(data, i);
//             exit(0);
//         }
//         i++;
//     }
// }

