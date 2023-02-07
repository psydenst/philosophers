// INCLUIR 42 HEADER

#include "../inc/philo.h"

int	ft_strdigit(char **joker, t_count *data)
{
	int	offset;

	data->number = 0;
	offset = 1;
	while (joker[offset])
	{
		data->i = 0;
		while (joker[offset][data->i] == ' ' || joker[offset][data->i] == '-')
			data->i++;
		while (joker[offset][data->i] >= '0' && joker[offset][data->i] <= '9')
		{
			data->i++;
			data->number++;
		}
		data->i = 0;
		if (joker[offset][data->i] == '-' || joker[offset][data->i] == '+')
			data->i++;
		if (ft_strdigit2(joker, data->i, offset, data->number) == 0
			|| joker[offset][data->i] == 0)
			return (0);
	offset++;
	}
	if (data->number == 0)
		return (0);
	return (1);
}

int	ft_strdigit2(char **joker, int i, int offset, int number)
{
	while (joker[offset][i] >= '0' && joker[offset][i] <= '9')
	{
		i++;
		number++;
	}
	i = 0;
	while (joker[offset][i])
	{
		if ((joker[offset][i] < '0' || joker[offset][i] > '9')
		&& joker[offset][i] != ' ' && joker[offset][i] != '+'
		&& joker[offset][i] != '-')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int verification_main(int argc, char *argv[], t_data *data)
{
    t_count count;

    if (argc < 5 || argc > 6)
        return(printf("Wrong number of arguments"));  
    if (ft_strdigit(argv, &count) == 0)
        return (printf("Non-numeric input :/"));
    data->nbr_ph = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
	data->nbr_ph = data->nbr_ph;
	data->argc = argc;
    if (argc == 6 )
        data->nbr_ph_eat = ft_atoi(argv[5]);
    return (1);
}
