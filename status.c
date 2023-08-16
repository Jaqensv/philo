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

int	check_death(t_phl *current_philo)
{
	if (current_philo->last_meal > current_philo->phl_link->time_to_die)
		return (1);
	return (0);
}

void	print_routine(t_phl *current_philo)
{
	print(current_philo, "has taken a fork");
	pthread_mutex_lock(&current_philo->left_fork);
	print(current_philo, "has taken a fork");
	pthread_mutex_lock(&current_philo->right_fork);
	print(current_philo, "is eating");
	pthread_mutex_unlock(&current_philo->left_fork);
	pthread_mutex_unlock(&current_philo->right_fork);
	current_philo->last_meal = 0;
	printf("last meal %d\n", current_philo->last_meal);
	my_usleep(current_philo->phl_link->time_to_eat);
	print(current_philo, "is sleeping");
	my_usleep(current_philo->phl_link->time_to_sleep);
}

int	print(t_phl *current_philo, char *str)
{
	long int	time;

	time = get_time() - (current_philo->phl_link->start_time / 100);
	//printf("get time = %ld\n", get_time());
	//printf("start time = %ld\n", current_philo->phl_link->start_time);
	current_philo->last_meal += get_time();
	printf("last meal %d\n", current_philo->last_meal);
	//printf("time = %ld\n", time);
	// if (check_death(current_philo) == 1)
	// 	return (exit(printf("[%ld] philo %d has died ! \n", time, current_philo->philo_id)), 1);
	printf("[%ld] philo %d %s \n", time, current_philo->philo_id, str);
	return (0);
}
