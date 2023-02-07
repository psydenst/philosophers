/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:51:17 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/07 15:52:31 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

#define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>


typedef pthread_mutex_t t_mutex;

typedef struct s_data t_data;

typedef	struct s_philo
{
	int		id;
	int		left_fork;
	int		right_fork;
	long long	last_meal;
	int		meals;
	t_data	*data;
	pthread_t	th;
	long long	start;
} t_philo;

typedef	struct s_count
{
	int i;
	int number;
} t_count;

typedef struct s_data
{
	long long	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_ph_eat;
	int	nbr_ph;
	int	death;
	t_philo	*philos;
	t_mutex	*mutex;
	t_mutex	monitor;
	long long start;
	int		argc;
} t_data;

// MAIN.C
void	*routine(void *args);
void	init_threads(t_data *data);

// UTILS.C
long int		ft_atoi(const char *str);
long	long	ft_at_time(void);
long	long	ft_time_in_mls(void);
long	long	ft_present(long long now, long long then);
void			hypnos(long long time, t_data *data);

// ROUTINES.C
void	fork_ph(t_philo *ph);
void    to_eat(t_philo *ph);
void    to_sleep(t_philo *ph);
void	to_think(t_philo *ph);
void    to_die(t_data *data, int i);
void	printf_safe(long long time, t_philo *ph, char * message);

// VERIFICATION.C
int verification_main(int argc, char *argv[], t_data *data);
int	ft_strdigit(char **joker, t_count *data);
int	ft_strdigit2(char **joker, int i, int offset, int number);

// POPULATE_PHIL.C
void    philosophai(t_data *data);
int		meal_amount(t_data *data);

// FORKS.C
void	fork_ketron(t_data *data, t_philo *philos);
void	fork_coordenation(t_philo *philos, int i);

// MUTEX.C
void    ft_mutex_init(t_data *data);
void	*monitoring(void *args);
void	ft_mutex_destroy(t_data *data);
void	simulation_over(void);
void	*monitoring2(t_data *data);

#endif
