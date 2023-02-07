/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:51:31 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/06 22:38:38 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/philo.h"

int	rd_var(int value, pthread_mutex_t *mtx);

int verify(t_philo *ph)
{
  //printf("death %d meals %d npe %d !\n", ph->data->death, ph->meals, ph->data->nbr_ph_eat);
  pthread_mutex_lock(&ph->data->monitor);
  if (!ph->data->death)
  {
		pthread_mutex_unlock(&ph->data->monitor);
		return (0);
  }
  pthread_mutex_unlock(&ph->data->monitor);
  return (1);
}

void    fork_ph(t_philo *ph)
{
	if (verify(ph))
		return ;
    pthread_mutex_lock(&ph->data->mutex[ph->left_fork]);
    printf("%llims %d has taken a fork\n", ft_time_in_mls() - ph->data->start , ph->id);
    pthread_mutex_lock(&ph->data->mutex[ph->right_fork]);
	printf("%llims %d has taken a fork\n", ft_time_in_mls() - ph->data->start , ph->id);
}

void	to_eat(t_philo *ph)
{
	if (verify(ph))
		return ;
	printf("%llims %d is eating\n", ft_time_in_mls() - ph->data->start , ph->id);
	pthread_mutex_lock(&ph->data->monitor);
	ph->meals++;
	// hypnos(ph->data->time_to_eat, ph->data); // criar smart_wait. 
    ph->last_meal = ft_time_in_mls();
	// printf("valor de last_meal: %lli\n", ph->last_meal);
	pthread_mutex_unlock(&ph->data->monitor);
	hypnos(ph->data->time_to_eat, ph->data);
//	usleep(ph->data->time_to_eat * 1000);
	pthread_mutex_unlock(&ph->data->mutex[ph->left_fork]);
    pthread_mutex_unlock(&ph->data->mutex[ph->right_fork]);
}

void	to_sleep(t_philo *ph)
{
	if (verify(ph))
		return ;
	printf("%llims %d is sleeping\n", ft_time_in_mls() - ph->data->start , ph->id);
	hypnos(ph->data->time_to_sleep, ph->data);
	//usleep(ph->data->time_to_sleep * 1000); // criar smart_wait. 
}

void	to_think(t_philo *ph)
{
	if (verify(ph))
		return ;
	printf("%llims %d is thinking\n", ft_time_in_mls() - ph->data->start , ph->id);
	usleep(150);
}
void	to_die(t_data *data, int i)
{
	if (rd_var((data->death == (i + 1)), &data->monitor))
		printf("%llims %d is dead\n", ft_time_in_mls() - data->start , data->philos[i].id);
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
