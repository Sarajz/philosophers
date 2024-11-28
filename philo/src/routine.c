/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:02:25 by sarajime          #+#    #+#             */
/*   Updated: 2024/11/28 21:19:25 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_msg(t_philo *philo, char *msg)
{
	size_t	time;

	time = get_current_time() - philo->time;
	pthread_mutex_lock(philo->m_write);
	if (!dead_flag(philo))
		printf("%ld %d %s", time, philo->dni + 1, msg);
	pthread_mutex_unlock(philo->m_write);
}

void	going_tosleep(t_philo *philo)
{
	ft_usleep(getter(philo->mt_sleep, philo->t_sleep));
	print_msg(philo, SLEEP);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, FORK);
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, FORK);
	print_msg(philo, EAT);
	pthread_mutex_lock(&philo->mt_last_meal);
	philo->last_t_eat = get_current_time();
	philo->num_meals++;
	pthread_mutex_unlock(&philo->mt_last_meal);
	ft_usleep(getter(philo->mt_eat, philo->t_eat));
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->dni % 2 == 0)
		ft_usleep(1);
	while (!dead_flag(philo))
	{
		if (philo->num_meals == philo->limit_meals)
			break ;
		if (!dead_flag(philo))
			eat(philo);
		if (!dead_flag(philo))
			going_tosleep(philo);
		if (!dead_flag(philo))
			print_msg(philo, THINK);
	}
	return (NULL);
}

void	*solo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_msg(philo, FORK);
	while (!dead_flag(philo))
		;
	return (NULL);
}
