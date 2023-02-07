/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:51:31 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/07 18:16:30 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/philo.h"

void	fork_ph(t_philo *ph)
{
	if (verify(ph))
		return ;
	pthread_mutex_lock(&ph->data->mutex[ph->left_fork]);
	printf_safe(ft_time_in_mls() - ph->data->start, ph, "has taken a fork");
	pthread_mutex_lock(&ph->data->mutex[ph->right_fork]);
	printf_safe(ft_time_in_mls() - ph->data->start, ph, "has taken a fork");
}

void	to_eat(t_philo *ph)
{
	if (verify(ph))
		return ;
	fork_ph(ph);
	printf_safe(ft_time_in_mls() - ph->data->start, ph, "is eating");
	pthread_mutex_lock(&ph->data->monitor);
	ph->meals++;
	ph->last_meal = ft_time_in_mls();
	pthread_mutex_unlock(&ph->data->monitor);
	hypnos(ph->data->time_to_eat, ph->data);
	pthread_mutex_unlock(&ph->data->mutex[ph->left_fork]);
	pthread_mutex_unlock(&ph->data->mutex[ph->right_fork]);
}

void	to_sleep(t_philo *ph)
{
	if (verify(ph))
		return ;
	printf_safe(ft_time_in_mls() - ph->data->start, ph, "is sleeping");
	hypnos(ph->data->time_to_sleep, ph->data);
}

void	to_think(t_philo *ph)
{
	if (verify(ph))
		return ;
	printf_safe(ft_time_in_mls() - ph->data->start, ph, "is thinking");
	usleep(150);
}

void	to_die(t_data *data, int i)
{
	if (rd_var((data->death == (i + 1)), &data->monitor))
		printf("%llims %d is dead\n", ft_time_in_mls() - data->start,
			data->philos[i].id);
}
