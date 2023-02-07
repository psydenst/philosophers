/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:48:18 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/06 18:05:04 by thfirmin         ###   ########.fr       */
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

void fork_coordenation(t_philo *philos, int i)
{
		//printf("dent: %p\n", philos);
        philos[i].left_fork = ft_get_lfork(&philos[i]);
    	//printf("mutex adress of left fork %i %p\n", philos.id, &philos.data->mutex[philos.left_fork]);
        philos[i].right_fork = ft_get_rfork(&philos[i]);
		//printf("L> %d\n", philos[i].left_fork + 1);
		//printf("R> %d\n", philos[i].right_fork + 1);
    	//printf("mutex adress of right %i %p\n", philos.id, &philos.data->mutex[philos.rigth_fork]);
}

void	fork_ketron(t_data *data, t_philo *philos)
{
    int i;

    i = 0;
    while (i < data->nbr_ph)
    {
		//printf("antes[%i]: %d(L) %d(R)\n", i+1, philos->left_fork + 1, philos->right_fork + 1);
		//printf("fora: %p\n", philos);
        fork_coordenation(philos, i);
		// printf("depoi[%i]: %d(L) %d(R)\n", i + 1, philos[i].left_fork + 1, philos[i].right_fork + 1);
		//printf("============\n");
		//printf("depoi[%i]: %p\n", i+1, &philos[i]);
        i++;
    }
}


