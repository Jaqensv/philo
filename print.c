/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:47:13 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/22 22:12:00 by mde-lang         ###   ########.fr       */
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
