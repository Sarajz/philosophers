/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:56:59 by sarajime          #+#    #+#             */
/*   Updated: 2024/09/04 18:55:39 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_table(t_table *table)
{
	printf("PHILOS: %d, T_DIE: %d, T_EAT: %d, T_SLEEP: %d, MAX_MEALS: %d\n", table->num_philo, table->t_die, table->t_eat, table->t_sleep, table->max_meals);
}

// philo, tiempo morir, comer, dormir, comidas max.