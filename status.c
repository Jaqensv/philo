/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:32:04 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/17 00:06:54 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_table *data_table)
{
	if (data_table->philos->last_meal > data_table->philos->phl_link->time_to_die)
		return (exit(printf("[%ld] philo %d has died ! \n", exe_time(data_table), data_table->philos->philo_id)), 1);
	return (0);
}

void	print_routine(t_phl *current_philo)
{
	print(current_philo, "has taken a fork");
	print(current_philo, "has taken a fork");
	print(current_philo, "is eating");
	current_philo->last_meal = 0;
	print(current_philo, "is sleeping");
}

int	print(t_phl *current_philo, char *str)
{
	current_philo->last_meal += get_time() - current_philo->phl_link->start_time;
	printf("[%ld] philo %d %s \n", exe_time(current_philo), current_philo->philo_id, str);
	return (0);
}
