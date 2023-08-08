/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:32:04 by mde-lang          #+#    #+#             */
/*   Updated: 2023/07/06 00:16:05 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_routine(t_phl *current_philo)
{
    //long int    time;

    // time = get_time();
    // printf("[%ld] ", time);
    printf("%d", current_philo->philo_id);
    printf(" ");
    printf("has taken a fork");
    printf("\n");
    return ;    
}