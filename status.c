/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:32:04 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/17 18:02:24 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	supervisor(t_table *table)
{
	table->start_time = get_time();
	while (1)
	{
		if ((table->phl_link->last_meal += get_time() - table->start_time) >= table->time_to_eat)
			return (0);
		printf("last meal = %d\n", table->phl_link->last_meal);
		if (table->phl_link->last_meal > table->time_to_die)
		{
			print(table->phl_link, "died !");
			exit(1);
		}
	}
	return (0);
}

void	*eating_time(t_phl *current_philo)
{
	while (exe_time(current_philo->table_link) < current_philo->table_link->time_to_eat)
		;
	current_philo->meal_nbr++;
	printf("start time = %ld\n", get_time() - current_philo->table_link->start_time);
	printf("meal nbr = %d\n", current_philo->meal_nbr);
	return (NULL);
}

void	print_routine(t_phl *current_philo)
{
	//pthread_mutex_lock(current_philo->left_fork);
	print(current_philo, "has taken a fork");
	//pthread_mutex_lock(current_philo->right_fork);
	print(current_philo, "has taken a fork");
	print(current_philo, "is eating");
	current_philo->last_meal = 0;
	eating_time(current_philo);
	//pthread_mutex_unlock(current_philo->left_fork);
	//pthread_mutex_unlock(current_philo->right_fork);
	print(current_philo, "is sleeping");
}

void	print(t_phl *current_philo, char *str)
{
	printf("[%ld] philo %d %s \n", exe_time(current_philo->table_link), current_philo->philo_id, str);
}
