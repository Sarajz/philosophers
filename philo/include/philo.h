/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:31:09 by sarajime          #+#    #+#             */
/*   Updated: 2024/11/26 18:24:52 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <fcntl.h>
# include <linux/limits.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

# define FORK "Has taken a fork\n"
# define EAT "Is eating\n"
# define SLEEP "Is sleeping\n"
# define THINK "Is thinking\n"
# define DIED "Died\n"

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				dni;
	int				num_meals;
	int				limit_meals;
	int				*t_eat;
	int				*t_sleep;
	size_t			time;
	size_t			last_t_eat;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	mt_last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*m_write;
	pthread_mutex_t	*mt_eat;
	pthread_mutex_t	*mt_sleep;
	pthread_mutex_t	*m_dead;
}					t_philo;

typedef struct s_table
{
	int				num_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_meals;
	int				start;
	int				dead;
	size_t			time;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	m_write;
	pthread_mutex_t	mt_eat;
	pthread_mutex_t	mt_sleep;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	*fork;
}					t_table;

long	ft_atol(const char *str);
int		is_digit(char c);
int		valid_arg(int argc, char **argv);
int		assing_fork(t_table *table);
void	init_p_mutex(t_table *table, t_philo *philo);
int		init_philo(t_table *table);
int		init_table(char **argv, t_table *table);
int		init_pthread(t_table *table);
void	print_table(t_table *table);
int		getter(pthread_mutex_t *mutex, int *var);
void	setter(pthread_mutex_t *mutex, int *var, int n);
void	print_msg(t_philo *philo, char *msg);
void	going_tosleep(t_philo *philo);
void	eat(t_philo *philo);
void	*routine(void *arg);
size_t	get_current_time(void);
int		ft_usleep(size_t ms);
void	*monitor(void *arg);
int		dead_flag(t_philo *philo);
void	bye_mutex(t_table *table);

#endif