/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:38:51 by sarajime          #+#    #+#             */
/*   Updated: 2024/09/04 18:53:47 by sarajime         ###   ########.fr       */
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
	print_table(&table);
}
