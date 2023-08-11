/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:53:00 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/11 14:27:00 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *arg) // Lorsque le thread arrive à la fin de cette fonction, il aura terminé toutes ses tâches.
{
	t_phl		*current_philo;

	current_philo = (t_phl *)arg;
	current_philo->forks_tab = malloc(sizeof(int) * current_philo->phl_link->philo_nb);
	//pthread_mutex_lock(&current_philo->phl_link->mutex);
	print_routine(current_philo);
	//pthread_mutex_unlock(&current_philo->phl_link->mutex);
	//pthread_detach(current_philo->philo_life);
	return (NULL);
}

void	parser(char **argv, t_table *data_table)
{
	data_table->philo_nb = ft_atoi(argv[1]);
	if (data_table->philo_nb < 1)
		wrong_param_pnb();
	data_table->time_to_die = ft_atoi(argv[2]);
	data_table->time_to_eat = ft_atoi(argv[3]);
	data_table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data_table->times_philo_must_eat = ft_atoi(argv[5]);
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

int	main(int argc, char **argv)
{
	t_table		data_table;
	int			i;

	i = 0;
	param_checker(argc, argv);
	parser(argv, &data_table);
	data_table.philos = malloc(sizeof(t_phl) * data_table.philo_nb);
	pthread_mutex_init(&data_table.mutex, NULL);
	data_table.start_time = get_time();
	while (i < data_table.philo_nb)
	{
		data_table.philos[i].philo_id = i + 1;
		data_table.philos[i].phl_link = &data_table;
		pthread_create(&data_table.philos[i].philo_life, NULL, &routine, &data_table.philos[i]);
		i++;
	}
	// while (1) // tant qu'aucun philo n'est mort
	// 	my_usleep((int)get_time);
	pthread_mutex_destroy(&data_table.mutex);
	// pthread_join(philo1, NULL);
	// system("leaks philo");
	return (0);
}


// compteur nbr de repas mangés par philo
// time quand philo a commencé à manger pour la derniere fois