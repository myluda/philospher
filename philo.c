#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>


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
	long lastime;
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

s_philo *ft_init_philo(s_philo *nbphilo, s_data *datas)
{
	int i;

	i = 0;
	if (!nbphilo)
		return (NULL);
	while(i++ < datas->nbphilo)
	{
		nbphilo[i].datas = datas;
	}
}

void	create_threads(s_data *datas)
{
	int i;

	i = 0;
	while(data)
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
		nbphilo = malloc(sizeof(s_philo) * datas->nbphilo);
		ft_init_philo(nbphilo,datas);	
	}
		
}
