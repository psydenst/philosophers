/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:39:01 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/06 22:21:01 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_mutex_init(t_data *data)
{
	int i; 

	i = 0; 
	data->mutex = malloc(data->nbr_ph * sizeof(t_mutex));
	while (i < data->nbr_ph)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->monitor, NULL);
}

void	ft_mutex_destroy(t_data *data)
{
	int i; 

	i = 0; 
	while (i < data->nbr_ph)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free(data->mutex);
}

void	simulation_over(void )
{
		exit(0);
}

void *monitoring(void *args)
{
	int	i;
	long long a;
	t_data *data;
	
	data = (t_data *)args;
	i = 0;
	while (1)
	{
		if (i > data->nbr_ph)
			i = 0;
		pthread_mutex_lock(&data->monitor);
		a = ft_time_in_mls();
		if (data->philos[i].meals > 0 && data->philos[i].last_meal != 0)
			if (ft_present(a, data->philos[i].last_meal) > data->time_to_die)
			{
				// printf("%i meals de philo %i\n", data->philos[i].meals, data->philos[i].id);
				// printf("last meal de %i %lli\n", data->philos[i].id, data->philos[i].last_meal);
				// printf("philos[].id: %i a - last_meal: %lli\n", data->philos[i].id, ft_present(a, data->philos[i].last_meal));
				data->death = i + 1;
				pthread_mutex_unlock(&data->monitor);
				return (0);
				//to_die(data, i);
				//simulation_over();
			}
		// if (ft_present(ft_time_in_mls(), data.philos[i].last_meal) > data->time_to_die)
		if (data->argc == 6)
		{
			if (meal_amount(data) == 1)
			{
				data->death = -1;
				pthread_mutex_unlock(&data->monitor);
				return (0);

			}
		}
				//simulation_over();
		pthread_mutex_unlock(&data->monitor);
		i++;
	}
	//pthread_mutex_destroy(&data->monitor);
}

int	meal_amount(t_data *data)
{
	int i;
	int a;

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
