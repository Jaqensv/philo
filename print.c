/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:32:04 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/11 14:29:05 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_routine(t_phl *current_philo)
{
	print(current_philo, "has taken a fork");
	print(current_philo, "has taken a fork");
	print(current_philo, "is eating");
	my_usleep(current_philo->phl_link->time_to_eat);
	print(current_philo, "is sleeping");
	my_usleep(current_philo->phl_link->time_to_sleep);
}

void	print(t_phl *current_philo, char *str)
{
	long int	time;

	time = get_time() - current_philo->phl_link->start_time;
	printf("[%ld] philo %d %s \n", time, current_philo->philo_id, str);
}
