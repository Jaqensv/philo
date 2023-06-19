/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:42:53 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/17 19:27:48 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wrong_param_nb(void)
{
	write(1, "Wrong param number\n", 20);
	exit(1);
}

void	wrong_param_alpha(void)
{
	write(1, "Wrong param (alpha)\n", 21);
	exit(1);
}

void	wrong_param_negative(void)
{
	write(1, "Wrong param (negative)\n", 24);
	exit(1);
}

void	wrong_param_space(void)
{
	write(1, "Wrong param (space)\n", 24);
	exit(1);
}

void	wrong_param_pnb(void)
{
	write(1, "We need at least one philosopher\n", 34);
	exit(1);
}
