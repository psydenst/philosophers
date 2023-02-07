/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:40:29 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/06 18:45:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int	ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
	{
		if (sign == -1)
			return (0);
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (sign * result);
}

long	long	ft_time_in_mls(void)
{
	struct timeval	time; 
	
	gettimeofday(&time, NULL);
	return ((((time.tv_sec * 1000) + (time.tv_usec / 1000))));
}

long	long	ft_present(long long now, long long then)
{
	return (now - then);
}

void	hypnos(long long time, t_data *data)
{
	long	long	then;
	long	long	now;

	then = ft_time_in_mls();
	while (1)
	{
		pthread_mutex_lock(&data->monitor);
		if (data->death)
		{
			pthread_mutex_unlock(&data->monitor);
			break ;
		}
		pthread_mutex_unlock(&data->monitor);
		now = ft_time_in_mls();
		if (ft_present(now, then) >= time)
			break;
		usleep(250);
	}
}
