/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:39:01 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/07 17:50:51 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_mutex_init(t_data *data)
{
	int	i;

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
	int	i;

	i = 0;
	while (i < data->nbr_ph)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free (data->mutex);
}

int	is_bigger(long long a, long long last_meal, t_data *data)
{
	long long	now;

	now = ft_present(a, last_meal);
	if (now > data->time_to_die)
		return (1);
	else
		return (0);
}

void	*monitoring(void *args)
{
	int			i;
	long long	a;
	t_data		*data;

	data = (t_data *)args;
	i = 0;
	while (1)
	{
		if (i > data->nbr_ph)
			i = 0;
		pthread_mutex_lock(&data->monitor);
		a = ft_time_in_mls();
		if (data->philos[i].meals > 0 && data->philos[i].last_meal != 0)
		{
			if (is_bigger(a, data->philos[i].last_meal, data))
			{
				data->death = i + 1;
				pthread_mutex_unlock(&data->monitor);
				return (0);
			}
		}
		monitoring2(data);
		i++;
	}
	pthread_mutex_destroy(&data->monitor);
}

void	*monitoring2(t_data *data)
{
	if (data->argc == 6)
	{
		if (meal_amount(data) == 1)
		{
			data->death = -1;
			pthread_mutex_unlock(&data->monitor);
			return (0);
		}
	}
	pthread_mutex_unlock(&data->monitor);
	usleep(100);
	return (0);
}
