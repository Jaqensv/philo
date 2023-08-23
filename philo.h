/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:49:15 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/22 23:00:29 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_phl	t_phl;

typedef struct s_table
{
	int				philo_nb;
	long int		start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_philo_must_eat;
	int				death;
	pthread_t		supervisor;
	t_phl			*phl_link;
	int				phl_end;
	pthread_mutex_t	*forks_tab;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	phl_end_mutex;
}					t_table;

typedef struct s_phl
{
	t_table			*table_link;
	int				philo_id;
	long int		death_time;
	int				meal_nbr;
	pthread_mutex_t	death_time_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_t		philo_life;
}					t_phl;

void			print_routine(t_phl *philo);
void			my_usleep(long int time_in_ms);
void			print(t_phl *philo, char *str);
void			print_error(char *str);
void			*supervisor(void *arg);
void			*routine(void *arg);
void			free_for_all(t_table *table);
int				check_death(t_table *table);
int				check_food(t_table *table);
int				stop(t_table *table);
long int		get_time(void);
long int		exe_time(t_table *table);
long long int	ft_atoi(const char *str);

#endif