/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:57:33 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/23 14:09:05 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	ft_atoi(const char *str)
{
	int				i;
	int				booleen;
	long long int	n;

	i = 0;
	booleen = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			booleen *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	return (n * booleen);
}

long int	get_time(void)
{
	struct timeval	actual_time;

	if (gettimeofday(&actual_time, NULL) == -1)
		printf("Gettimeofday returned -1\n");
	return (actual_time.tv_sec * 1000 + actual_time.tv_usec / 1000);
}

long int	exe_time(t_table *table)
{
	long int	exe_time;

	exe_time = get_time() - table->start_time;
	return (exe_time);
}

void	my_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(100);
}

void	free_for_all(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->philo_nb)
	{
		pthread_mutex_destroy(&table->forks_tab[i]);
		pthread_mutex_destroy(&table->phl_link[i].meal_mutex);
		pthread_mutex_destroy(&table->phl_link[i]
			.death_time_mutex);
	}
	pthread_mutex_destroy(&table->death_mutex);
	pthread_mutex_destroy(&table->phl_end_mutex);
	free(table->phl_link);
	free(table->forks_tab);
}
