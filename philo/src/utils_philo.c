/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:53:45 by sarajime          #+#    #+#             */
/*   Updated: 2024/11/29 14:15:11 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	getter(pthread_mutex_t *mutex, int *var)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *var;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	setter(pthread_mutex_t *mutex, int *var, int n)
{
	pthread_mutex_lock(mutex);
	*var = n;
	pthread_mutex_unlock(mutex);
}

int	dead_flag(t_philo *philo)
{
	pthread_mutex_lock(philo->m_dead);
	if (philo->table->dead == 1)
	{
		pthread_mutex_unlock(philo->m_dead);
		return (1);
	}
	pthread_mutex_unlock(philo->m_dead);
	return (0);
}

void	bye_mutex(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philo)
		pthread_mutex_destroy(&table->fork[i]);
	pthread_mutex_destroy(&table->m_dead);
	pthread_mutex_destroy(&table->m_write);
	pthread_mutex_destroy(&table->mt_eat);
	pthread_mutex_destroy(&table->mt_sleep);
}

int	init_pthread_routine(t_table *table, int i)
{
	while (++i < table->num_philo)
	{
		table->philo[i].time = get_current_time();
		if (pthread_create(&table->philo[i].thread,
				NULL, &routine, &(table->philo[i])))
			return (printf("No thread routine\n"), 1);
	}
	return (0);
}
