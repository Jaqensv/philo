/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:47:13 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/25 21:52:11 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_phl *philo, char *str)
{
	pthread_mutex_lock(&philo->table_link->death_mutex);
	if (philo->table_link->death == 0)
		printf("%ld %d %s\n",
			exe_time(philo->table_link), philo->philo_id, str);
	pthread_mutex_unlock(&philo->table_link->death_mutex);
}

void	print_error(char *str)
{
	printf("%s \n", str);
}

void	one_philo(t_table *table)
{
	printf("%ld %d has taken a fork\n",
		exe_time(table), table->phl_link->philo_id);
	my_usleep(table->time_to_die, table);
	printf("%ld %d has died !\n",
		exe_time(table), table->phl_link->philo_id);
	free_for_all(table);
}
