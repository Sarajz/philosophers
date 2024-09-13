/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:27:50 by sarajime          #+#    #+#             */
/*   Updated: 2024/09/13 19:05:25 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	assing_fork(t_table *table)
{
	int	i;

	i = -1;
	table->fork = malloc(sizeof(pthread_mutex_t) * (table->num_philo));
	if (!table->fork)
		return (1);
	while (++i < table->num_philo)
		if (pthread_mutex_init(&table->fork[i], NULL))
			return (printf("No init forks\n"), 1);
	i = -1;
	while (++i < table->num_philo - 1)
	{
		table->philo[i].l_fork = &table->fork[i];
		table->philo[i].r_fork = &table->fork[i + 1];
	}
	table->philo[i].l_fork = &table->fork[i];
	table->philo[i].r_fork = &table->fork[0];
	return (0);
}

void	init_p_mutex(t_table *table, t_philo *philo)
{
	philo->m_write = &table->m_write;
	philo->mt_eat = &table->mt_eat;
	philo->mt_sleep = &table->mt_sleep;
}

int	init_philo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philo)
	{
		table->philo[i].dni = i;
		table->philo[i].num_meals = 0;
		table->philo[i].t_eat = &table->t_eat;
		table->philo[i].time = get_current_time();
		table->philo[i].last_t_eat = get_current_time();
		table->philo[i].limit_meals = table->max_meals;
		init_p_mutex(table, &table->philo[i]);
		if (pthread_mutex_init(&table->philo[i].mt_last_meal, NULL))
			return (printf("No mutex last time of eat\n"), 1);
	}
	assing_fork(table);
	i = -1;
	if (pthread_create(&table->monitor,
			NULL, &monitor, &(table->philo[i])))
		return (printf("No thread monitor\n"), 1);
	while (++i < table->num_philo)
	{
		if (pthread_create(&table->philo[i].thread,
				NULL, &routine, &(table->philo[i])))
			return (printf("No thread routine\n"), 1);
	}
	while (--i >= 0)
		if (pthread_join(table->philo[i].thread, NULL))
			return (printf("No join thread\n"), 1);
	if (pthread_join(table->monitor, NULL))
		return (printf("No join monitor thread\n"), 1);
	return (0);
}

int	init_table(char **argv, t_table *table)
{
	table->num_philo = ft_atol(argv[1]);
	if (table->num_philo < 0 || table->num_philo > 200)
		return (printf("Invalid num of philos\n"), 1);
	table->philo = malloc(sizeof(t_philo) * (table->num_philo));
	if (!table->philo)
		return (1);
	table->dead = 0;
	table->t_die = ft_atol(argv[2]);
	table->t_eat = ft_atol(argv[3]);
	table->t_sleep = ft_atol(argv[4]);
	table->max_meals = -1;
	if (argv[5])
		table->max_meals = ft_atol(argv[5]);
	if (pthread_mutex_init(&table->m_write, NULL))
		return (printf("No mutex write\n"), 1);
	if (pthread_mutex_init(&table->mt_eat, NULL))
		return (printf("No mutex eat\n"), 1);
	if (pthread_mutex_init(&table->mt_sleep, NULL))
		return (printf("No mutex sleep\n"), 1);
	init_philo(table);
	return (0);
}
