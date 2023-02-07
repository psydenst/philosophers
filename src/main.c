/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:11:59 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/07 14:26:27 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/philo.h"
#include <pthread.h>

void	*routine(void *args)
{
	t_philo	*philos;

	philos = (t_philo *)args;
	if (philos->id % 2 == 0)
		usleep(2000);
	while (1)
	{
		pthread_mutex_lock(&philos->data->monitor);
		if (philos->data->death != 0)
		{
			pthread_mutex_unlock(&philos->data->monitor);
			break ;
		}
		pthread_mutex_unlock(&philos->data->monitor);
		to_eat(philos);
		to_sleep(philos);
		to_think(philos);
	}
	to_die(philos->data, philos->id - 1);
	return (0);
}

void	exception(t_data *data)
{
	long long	start;

	start = (long long)ft_time_in_mls;
	if (data->nbr_ph == 1)
	{
		printf("%llims 1 has taken a fork\n",
			(long long) ft_time_in_mls - start);
		usleep(data->time_to_die * 1000);
		printf("%llims 1 is dead\n", (long long) data->time_to_die);
	}
	if (data->nbr_ph == 0)
		printf("Wrong input!\n");
}

void	freeing(t_data *data)
{
	free(data->philos);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (verification_main(argc, argv, &data) != 1)
		return (0);
	if (data.nbr_ph == 1 || data.nbr_ph == 0)
	{
		exception(&data);
		return (0);
	}
	ft_mutex_init(&data);
	philosophai(&data);
	fork_ketron(&data, data.philos);
	init_threads(&data);
	freeing(&data);
	return (0);
}

void	init_threads(t_data *data)
{
	pthread_t	ver;
	int			i;

	i = 0;
	data->start = ft_time_in_mls();
	while (i < data->nbr_ph)
	{		
		pthread_create(&data->philos[i].th, NULL, &routine, &data->philos[i]);
		i++;
	}
	pthread_create(&ver, NULL, &monitoring, data);
	i = 0;
	while (i < data->nbr_ph)
	{
		pthread_join(data->philos[i].th, NULL);
		i++;
	}
	pthread_join(ver, NULL);
	ft_mutex_destroy(data);
}
