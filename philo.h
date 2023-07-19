/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:49:15 by mde-lang          #+#    #+#             */
/*   Updated: 2023/07/10 13:03:07 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# include <stdio.h>

typedef struct s_phl	t_phl;

typedef struct s_table
{
	int				philo_nb;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				times_philo_must_eat;
	t_phl			*philos;
	pthread_mutex_t	mutex;
}			t_table;

typedef struct s_phl
{
	t_table			*phl_link;
	int				philo_id;
	pthread_t		philo_life;
}			t_phl;

void			wrong_param_nb(void);
void			wrong_param_alpha(void);
void			wrong_param_negative(void);
void			wrong_param_space(void);
void			wrong_param_pnb(void);
void			print_routine(t_phl *current_philo);
long long int	ft_atoi(const char *str);

#endif