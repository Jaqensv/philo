#include "philo.h"

// si bool fork = 0, on mutex_lock // si fork = 1, on unlock.

void	forks_trade(t_phl current_philo)
{
	if (current_philo.philo_id == 1)
	{
		current_philo.forks_tab[0] = 1;
		current_philo.forks_tab[1] = 0;
		current_philo.phl_link->philo_nb = 0;
	}
	else if (current_philo.philo_id == current_philo.phl_link->philo_nb)
	{
		current_philo.forks_tab[current_philo.phl_link->philo_nb] = 1;
		current_philo.forks_tab[0] = 0;
		current_philo.forks_tab[(current_philo.phl_link->philo_nb) - 1] = 0;
	}
	else
	{
		current_philo.forks_tab[(current_philo.philo_id) - 1] = 1;
		current_philo.forks_tab[(current_philo.philo_id) - 2] = 0;
		current_philo.forks_tab[current_philo.philo_id] = 0;
	}
}

// void	locker(t_phl *current_philo)
// {
// 	static int 	i = 0;

// 	pthread_mutex_lock(&current_philo->phl_link->mutex);




// }