/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:53:45 by sarajime          #+#    #+#             */
/*   Updated: 2024/11/25 17:25:18 by sarajime         ###   ########.fr       */
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
