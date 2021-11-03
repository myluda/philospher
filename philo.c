/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 07:55:11 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/10/23 07:55:13 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>


typedef struct t_data
{
	long nbphilo;
	long timeat;
	long timesleep;
	long timetodie;
	long nbmeals;
	int  all;
	pthread_mutex_t		*forks;
	pthread_mutex_t     write;
	pthread_mutex_t     eat;
	s_philo             *philos;
}s_data;

typedef struct t_philo
{
	pthread_t   thread;
	int id;
	long start;
	long lastime_eat;
	int nb_of_meals;
	int is_eating;
	s_data *datas;
}	s_philo;

int	parse_is_good(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > '9' || av[i][j] < '0' || ft_strlen(av[i]) > 10)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parsing(s_data *args,char **argv,int argc)
{
	if (parse_is_good(argv))
	{
		args->all = 0;
		args->nbphilo = atoi(argv[1]);
		if(args->nbphilo == 0)
			return (0);
		args->timetodie = atoi(argv[2]);
		args->timeat = atoi(argv[3]);
		args->timesleep = atoi(argv[4]);
		if (argc == 6)
			args->nbmeals = atoi(argv[5]);
		else
			args->nbmeals = -1;
	}
	return parse_is_good(argv);
}

void    *work(void *philosophers)
{
    s_philo *philo;
    philo = (s_philo *)philosophers;
}

int     time_now()
{

}
s_philo *ft_init_philo(s_philo *nbphilo, s_data *datas)
{
	int i;

	i = 0;
    nbphilo = malloc(sizeof(s_philo) * datas->nbphilo);
	if (!nbphilo)
		return (NULL);
	while(i++ < datas->nbphilo)
	{
        nbphilo[i].datas = datas;
		nbphilo[i].id = i;
        nbphilo[i].is_eating = 0;
        nbphilo[i].nb_of_meals = 0;
        nbphilo[i].lastime_eat = time_now();
        nbphilo[i].start = nbphilo->lastime_eat;
	}
}

void	init_threads(s_data *datas)
{
	int i;

	i = 0;
    datas->forks = malloc((datas->nbphilo) * sizeof(pthread_mutex_t));
	while(i++ < datas->nbphilo)
        pthread_mutex_init(&datas->forks[i],NULL);
    pthread_mutex_init(&datas->write,NULL);
    pthread_mutex_init(&datas->eat,NULL);
}

void    ft_start(s_data *datas, s_philo *nbphilo)
{
    int i;

    nbphilo = ft_init_philo(nbphilo,datas);
    init_threads(datas);

}

int main(int argc , char **argv)
{
	s_data *datas;
	s_philo *nbphilo;

	datas = NULL;
	if (argc == 5 || argc == 6)
	{
		if	(!ft_parsing(datas,argv,argc))
			exit(0);
		ft_start(datas,nbphilo);
	}
		
}
