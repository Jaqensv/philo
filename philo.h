/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:49:15 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/19 19:05:48 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# include <stdio.h>

void			wrong_param_nb(void);
void			wrong_param_alpha(void);
void			wrong_param_negative(void);
void			wrong_param_space(void);
void			wrong_param_pnb(void);
long long int	ft_atoi(const char *str);

typedef struct s_phl	t_phl;

typedef struct s_table
{
	int		philo_nb;// philosopher number
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	t_phl	**philos;
}		t_table;

typedef struct s_phl
{
	t_table		*phl_link;
	int			philo_id;
	pthread_t	philo_life;
}			t_phl;

#endif