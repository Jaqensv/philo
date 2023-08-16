/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:49:15 by mde-lang          #+#    #+#             */
/*   Updated: 2023/08/17 00:10:08 by mde-lang         ###   ########.fr       */
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

// #define FM "has taken a fork"
// #define IE "IS EATING"

typedef struct s_phl	t_phl;
typedef struct s_table	t_table;

typedef struct s_table

typedef struct s_table
{
	int				philo_nb;
	long int		start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_philo_must_eat;
	t_phl			*phl_link;
	pthread_mutex_t	*forks_tab;
	pthread_mutex_t	mutex;
}					t_table;

typedef struct s_phl
{
	t_table			*table_link;
	int				philo_id;
	int				last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		philo_life;
}					t_phl;

void			wrong_param_nb(void);
void			wrong_param_alpha(void);
void			wrong_param_negative(void);
void			wrong_param_space(void);
void			wrong_param_pnb(void);
void			print_routine(t_phl *current_philo);
void			my_usleep(long int time_in_ms);
int				print(t_phl *current_philo, char *str);
int				check_death(t_table *data_table);
long int		get_time(void);
long int		exe_time(t_phl *current_philo);
long long int	ft_atoi(const char *str);

#endif