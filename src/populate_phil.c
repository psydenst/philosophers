/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_phil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:06:53 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/07 18:16:01 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	philosophing(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->nbr_ph);
	i = 0;
	data->death = 0;
	while (i < data->nbr_ph)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].meals = 0;
		i++;
	}
}

void	printf_safe(long long time, t_philo *ph, char *message)
{
	if (verify(ph))
		return ;
	else
		printf("%llims %i %s\n", time, ph->id, message);
}

int	rd_var(int value, pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
	if (value)
	{
		pthread_mutex_unlock(mtx);
		return (1);
	}
	pthread_mutex_unlock(mtx);
	return (0);
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

int	verify(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->monitor);
	if (!ph->data->death)
	{
		pthread_mutex_unlock(&ph->data->monitor);
		return (0);
	}
	pthread_mutex_unlock(&ph->data->monitor);
	return (1);
}
