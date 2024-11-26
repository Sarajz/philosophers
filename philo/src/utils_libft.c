/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:44:21 by sarajime          #+#    #+#             */
/*   Updated: 2024/11/26 17:11:58 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	valid_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!is_digit(argv[i][j]))
				return (1);
		}
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < 0)
			return (printf("Invalid argv\n"), 1);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	i;
	long	j;
	long	result;

	i = 0;
	j = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * j);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
