/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:48:18 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/07 17:55:22 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static unsigned int	ft_get_rfork(t_philo *ph)
{
	if (ph->id == 1)
		return (ph->data->nbr_ph - 1);
	else
		return (ph->id - 2);
}

static unsigned int	ft_get_lfork(t_philo *ph)
{
	return (ph->id - 1);
}

void	fork_coordenation(t_philo *philos, int i)
{
	philos[i].left_fork = ft_get_lfork(&philos[i]);
	philos[i].right_fork = ft_get_rfork(&philos[i]);
}

void	fork_main(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nbr_ph)
	{
		fork_coordenation(philos, i);
		i++;
	}
}
