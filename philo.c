/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:53:00 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/22 21:08:17 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *arg)
{
	t_phl		*philo;

	philo = (t_phl *)arg;
	if (philo->philo_id % 2 == 0)
		my_usleep(2);
	while (1)
	{
		pthread_mutex_lock(&philo->table_link->death_mutex);
		if (philo->table_link->death == 1 || philo->table_link->meal_nbr_reached == 1)
		{
			pthread_mutex_unlock(&philo->table_link->death_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->table_link->death_mutex);
		print_routine(philo);
	}
	return (NULL);
}

void	parser(char **argv, t_table *table)
{
	table->philo_nb = ft_atoi(argv[1]);
	if (table->philo_nb < 1)
		print_error("We need at least one philosopher");
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->times_philo_must_eat = ft_atoi(argv[5]);
}

void	param_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 5 || argc > 6)
		print_error("wrong_param_nb");
	while (argv[j])
	{
		while (argv[j][i])
		{
			if ((argv[j][i] >= 'a' && argv[j][i] <= 'z')
				|| (argv[j][i] >= 'A' && argv[j][i] <= 'Z'))
				print_error("Wrong param (alpha)");
			if (argv[j][i] == '-')
				print_error("Wrong param (negative)");
			if (argv[j][i] == ' ')
				print_error("Wrong param (space)");
			i++;
		}
		j++;
		i = 0;
	}
}

void	mutex_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
	{
		pthread_mutex_init(&table->forks_tab[i], NULL);
		pthread_mutex_init(&table->phl_link[i].death_time_mutex, NULL);
		pthread_mutex_init(&table->death_mutex, NULL);
		pthread_mutex_init(&table->phl_link[i].meal_mutex, NULL);
	}
}

int	main(int argc, char **argv)
{
	t_table		table;
	int			i;

	i = -1;
	param_checker(argc, argv);
	parser(argv, &table);
	table.phl_link = malloc(sizeof(t_phl) * table.philo_nb);
	table.forks_tab = malloc(sizeof(pthread_mutex_t) * table.philo_nb);
	mutex_init(&table);
	table.start_time = get_time();
	table.death = 0;
	table.meal_nbr_reached = 0;
	table.times_they_all_ate = 0;
	while (++i < table.philo_nb)
	{
		table.phl_link[i].meal_nbr = 0;
		table.phl_link[i].philo_id = i + 1;
		table.phl_link[i].table_link = &table;
		table.phl_link[i].death_time = get_time() + table.time_to_die;
	 	pthread_create(&table.phl_link[i].philo_life, NULL, &routine, &table.phl_link[i]);
	}
	pthread_create(&table.supervisor, NULL, &supervisor, &table);
	i = -1;
	while (++i < table.philo_nb)
		pthread_join(table.phl_link[i].philo_life, NULL);
	pthread_join(table.supervisor, NULL);
	//pthread_mutex_destroy(&table.phl_link->last_meal_mutex);
	return (0);
}
