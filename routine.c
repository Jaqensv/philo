/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:32:04 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/22 21:03:53 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor(void *arg)
{	
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (check_death(table) == 1 || (table->times_philo_must_eat > 0 && check_food(table) == 1))
		{
			pthread_mutex_lock(&table->death_mutex);
			table->death = 1;
			pthread_mutex_unlock(&table->death_mutex);
			break;
		}
	}
	return (NULL);
}

void	print_routine(t_phl *philo)
{
	if (philo->philo_id == philo->table_link->philo_nb)
		pthread_mutex_lock(&philo->table_link->forks_tab[0]);
	else
		pthread_mutex_lock(&philo->table_link->forks_tab[philo->philo_id]);
	pthread_mutex_lock(&philo->table_link->forks_tab[philo->philo_id - 1]);
	print(philo, "has taken a fork");
	print(philo, "has taken a fork");
	print(philo, "is eating");
	pthread_mutex_lock(&philo->death_time_mutex);
	philo->death_time = get_time() + philo->table_link->time_to_die;
	pthread_mutex_unlock(&philo->death_time_mutex);
	my_usleep(philo->table_link->time_to_eat);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meal_nbr++;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (philo->philo_id == philo->table_link->philo_nb)
		pthread_mutex_unlock(&philo->table_link->forks_tab[0]);
	else
		pthread_mutex_unlock(&philo->table_link->forks_tab[philo->philo_id]);
	pthread_mutex_unlock(&philo->table_link->forks_tab[philo->philo_id - 1]);
	print(philo, "is sleeping");
	my_usleep(philo->table_link->time_to_sleep);
	print(philo, "is thinking");
}

int	check_death(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
	{
		pthread_mutex_lock(&table->phl_link[i].death_time_mutex);
		if (get_time() > table->phl_link[i].death_time)
		{
			pthread_mutex_unlock(&table->phl_link[i].death_time_mutex);
			print(&table->phl_link[i], "died !");
			return (1);
		}
		pthread_mutex_unlock(&table->phl_link[i].death_time_mutex);
	}
	return (0);
}

int	check_food(t_table *table)
{
	int	i;
	int	nbr_of_meal_per_each_phl_finished_to_eat_before_die;

	i = -1;
	nbr_of_meal_per_each_phl_finished_to_eat_before_die = 0;
	while (++i < table->philo_nb)
	{
		pthread_mutex_lock(&table->phl_link[i].meal_mutex);
		if (table->phl_link[i].meal_nbr >= table->times_philo_must_eat)
		{
			pthread_mutex_unlock(&table->phl_link[i].meal_mutex);
			nbr_of_meal_per_each_phl_finished_to_eat_before_die++;
		}
		pthread_mutex_unlock(&table->phl_link[i].meal_mutex);
	}
	if (nbr_of_meal_per_each_phl_finished_to_eat_before_die == table->philo_nb)
		return (1);
	return (0);
}
