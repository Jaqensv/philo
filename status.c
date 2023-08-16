/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:32:04 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/17 01:16:31 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_table *data_table)
{
	data_table->phl_link->last_meal += get_time() - data_table->start_time;
	if (data_table->phl_link->last_meal > data_table->time_to_die)
		return (exit(printf("[%ld] philo %d has died ! \n", exe_time(data_table), data_table->phl_link->philo_id)), 1);
	return (0);
}

void	print_routine(t_phl *current_philo)
{
	printf("last meat = %d\n", current_philo->last_meal);
	print(current_philo, "has taken a fork");
	print(current_philo, "has taken a fork");
	print(current_philo, "is eating");
	current_philo->last_meal = 0;
	print(current_philo, "is sleeping");
}

void	print(t_phl *current_philo, char *str)
{
	printf("[%ld] philo %d %s \n", exe_time(current_philo->table_link), current_philo->philo_id, str);
}
