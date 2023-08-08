/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:57:33 by mde-lang          #+#    #+#             */
/*   Updated: 2023/07/10 13:06:17 by mde-lang         ###   ########.fr       */
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

	gettimeofday(&actual_time, NULL);	
	return ((actual_time.tv_sec * 1000) + (actual_time.tv_usec / 1000));
}
