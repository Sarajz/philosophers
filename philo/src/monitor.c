/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:26:31 by sarajime          #+#    #+#             */
/*   Updated: 2024/09/16 18:35:25 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_dead(t_table *table, int i)
{
	int	elapsed;

	elapsed = get_current_time() - getter(&table->philo[i].mt_last_meal,
			(int*)&table->philo[i].last_t_eat);
	printf("%d\n", elapsed);
	if (getter(&table->philo[i].mt_last_meal,
			(int*)&table->philo[i].num_meals) == table->max_meals)
		return (2);
	if (elapsed > table->t_die)
		return (1);
	return (0);
}

void	*monitor(void *arg)
{
	int		i;
	int		full;
	int		is_dead;
	t_table	*table;

	table = (t_table *)arg;
	while (table->dead != 1)
	{
		i = -1;
		full = 0;
		while (++i < table->num_philo && table->dead != 1)
		{
			is_dead = philo_dead(table, i);
			if (is_dead == 1)
			{
				table->dead = 1;
				print_msg(table->philo, DIED);
			}
			else if (is_dead == 2)
				full++;
		}
		if (table->num_philo == full)
			break ;
	}
	return (NULL);
}
