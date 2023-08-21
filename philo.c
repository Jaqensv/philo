/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:53:00 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/17 18:03:31 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *arg) // Lorsque le thread arrive à la fin de cette fonction, il aura terminé toutes ses tâches.
{
	t_phl		*current_philo;

	current_philo = (t_phl *)arg;
	while (current_philo->table_link->start_time == -1)
		;
	//pthread_mutex_lock(&current_philo->last_meal_mutex);
	//pthread_mutex_unlock(&current_philo->last_meal_mutex);
	print_routine(current_philo);
	//pthread_detach(current_philo->philo_life); // peut causer du data race
	return (NULL);
}

void	parser(char **argv, t_table *table)
{
	table->philo_nb = ft_atoi(argv[1]);
	if (table->philo_nb < 1)
		wrong_param_pnb();
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->times_philo_must_eat = ft_atoi(argv[5]);
	table->start_time = get_time();
}

void	param_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 5 || argc > 6)
		wrong_param_nb();
	while (argv[j])
	{
		while (argv[j][i])
		{
			if ((argv[j][i] >= 'a' && argv[j][i] <= 'z')
				|| (argv[j][i] >= 'A' && argv[j][i] <= 'Z'))
				wrong_param_alpha();
			if (argv[j][i] == '-')
				wrong_param_negative();
			if (argv[j][i] == ' ')
				wrong_param_space();
			i++;
		}
		j++;
		i = 0;
	}
}

void	mutex_init(t_phl phl_link)
{
	pthread_mutex_init(&phl_link.last_meal_mutex, NULL);


}

int	main(int argc, char **argv)
{
	t_table		table;
	int			i;

	i = 0;
	param_checker(argc, argv);
	parser(argv, &table);
	table.phl_link = malloc(sizeof(t_phl) * table.philo_nb);
	//table.forks_tab = malloc(sizeof(pthread_mutex_t) * table.philo_nb);
	table.start_time = -1;
	while (i < table.philo_nb)
	{
		table.phl_link[i].philo_id = i + 1;
		table.phl_link[i].table_link = &table;
		//pthread_mutex_init(&table.phl_link[i].last_meal_mutex, NULL);
		//pthread_mutex_init(&table.phl_link[i].left_fork, NULL);
		//pthread_mutex_init(&table.phl_link[i].right_fork, NULL);
		//mutex_init(table.phl_link[i]);
		table.phl_link[i].meal_nbr = 0;
		pthread_create(&table.phl_link[i].philo_life, NULL, &routine, &table.phl_link[i]);
		i++;
	}
	supervisor(&table);
	//pthread_mutex_destroy(&table.phl_link->last_meal_mutex);
	//pthread_join(, NULL);
	//system("leaks philo");
	return (0);
}


// compteur nbr de repas mangés par philo
// time quand philo a commencé à manger pour la derniere fois