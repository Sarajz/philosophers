/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:38:51 by sarajime          #+#    #+#             */
/*   Updated: 2024/11/26 18:23:18 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (printf("Error num of argc\n"), 1);
	if (!valid_arg(argc, argv))
	{
		if (init_table(argv, &table))
			return (1);
	}
	else
		return (1);
	bye_mutex(&table);
	free(table.philo);
	free(table.fork);
}
