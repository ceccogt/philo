/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:35:28 by fgrisost          #+#    #+#             */
/*   Updated: 2024/07/22 11:35:28 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct t_philosopher
{
	int				eat;
	int				sleep;
	int				die;
	int				*is_alive;
	int				num;
	int				win;
	unsigned long	start;
	int				id;
	unsigned long	last_meal;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*last_meal_mutex;
	pthread_mutex_t	*is_alive_mutex;
	pthread_mutex_t	*win_mutex;
}	t_philosopher;

int	ft_mutex_int(int *j, pthread_mutex_t *mut)
{
	int	tmp;

	pthread_mutex_lock(mut);
	tmp = *j;
	pthread_mutex_unlock(mut);
	return (tmp);
}

void	custom_usleep(unsigned long usec)
{
	struct timeval	start;
	struct timeval	current;
	unsigned long	elapsed;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&current, NULL);
		elapsed = (current.tv_sec - start.tv_sec) * 1000000 + (current.tv_usec
				- start.tv_usec);
		if (elapsed >= usec)
		{
			break ;
		}
		usleep(50);
	}
}

void	*single_philo(void *philosopher)
{
	t_philosopher	*philo;
	int				left_fork;
	int				right_fork;
	int				i;
	struct timeval	print_time;

	philo = (t_philosopher *)philosopher;
	i = 0;
	if (philo->id != philo->num - 1)
	{
		left_fork = philo->id;
		right_fork = philo->id + 1;
	}
	else
	{
		right_fork = philo->id;
		left_fork = 0;
	}
	if (philo->id % 2 == 0)
		custom_usleep(3000);
	while (ft_mutex_int(&philo->win, philo->win_mutex) != 0
		&& ft_mutex_int(philo->is_alive, philo->is_alive_mutex))
	{
		pthread_mutex_lock(&philo->forks[left_fork]);
		pthread_mutex_lock(philo->print);
		gettimeofday(&(print_time), NULL);
		ft_printf("%u %i has taken a fork\n", ft_mutex_int(philo->is_alive,
				philo->is_alive_mutex), ((print_time.tv_sec * 1000)
				+ (print_time.tv_usec / 1000)) - philo->start, philo->id);
		pthread_mutex_unlock(philo->print);
		if (philo->num != 1)
			pthread_mutex_lock(&philo->forks[right_fork]);
		else
			custom_usleep(philo->die * 1000);
		pthread_mutex_lock(philo->print);
		gettimeofday(&(print_time), NULL);
		ft_printf("%u %i has taken a fork\n", ft_mutex_int(philo->is_alive,
				philo->is_alive_mutex), ((print_time.tv_sec * 1000)
				+ (print_time.tv_usec / 1000)) - philo->start, philo->id);
		gettimeofday(&(print_time), NULL);
		ft_printf("%u %i is eating\n", ft_mutex_int(philo->is_alive,
				philo->is_alive_mutex), ((print_time.tv_sec * 1000)
				+ (print_time.tv_usec / 1000)) - philo->start, philo->id);
		pthread_mutex_unlock(philo->print);
		custom_usleep(philo->eat * 1000);
		gettimeofday(&(print_time), NULL);
		pthread_mutex_lock(philo->last_meal_mutex);
		philo->last_meal = (print_time.tv_sec * 1000 + print_time.tv_usec
				/ 1000) - philo->start;
		pthread_mutex_unlock(philo->last_meal_mutex);
		if (philo->num != 1)
			pthread_mutex_unlock(&philo->forks[right_fork]);
		pthread_mutex_unlock(&philo->forks[left_fork]);
		pthread_mutex_lock(philo->print);
		gettimeofday(&(print_time), NULL);
		ft_printf("%u %i is sleeping\n", ft_mutex_int(philo->is_alive,
				philo->is_alive_mutex), ((print_time.tv_sec * 1000)
				+ (print_time.tv_usec / 1000)) - philo->start, philo->id);
		pthread_mutex_unlock(philo->print);
		custom_usleep(philo->sleep * 1000);
		pthread_mutex_lock(philo->print);
		gettimeofday(&(print_time), NULL);
		ft_printf("%u %i is thinking\n", ft_mutex_int(philo->is_alive,
				philo->is_alive_mutex), ((print_time.tv_sec * 1000)
				+ (print_time.tv_usec / 1000)) - philo->start, philo->id);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(philo->win_mutex);
		if (philo->win != -1)
			philo->win--;
		pthread_mutex_unlock(philo->win_mutex);
	}
	return (NULL);
}

void	*controller_func(void *philosophers)
{
	int				j;
	int				i;
	t_philosopher	*philo;
	struct timeval	now;
	int				num;
	unsigned long	micro;

	philo = (t_philosopher *)philosophers;
	num = philo->num;
	j = 0;
	i = 0;
	while (1)
	{
		j = 0;
		while (j < num)
		{
			pthread_mutex_lock(philo[j].last_meal_mutex);
			gettimeofday(&now, NULL);
			micro = ((now.tv_sec * 1000 + now.tv_usec / 1000) - philo[j].start)
				- philo[j].last_meal;
			pthread_mutex_unlock(philo[j].last_meal_mutex);
			if (micro > (unsigned long)philo[j].die)
			{
				pthread_mutex_lock(philo[j].is_alive_mutex);
				*(philo[j].is_alive) = 0;
				pthread_mutex_lock(philo[j].print);
				ft_printf("%u %i died\n", 1, ((now.tv_sec * 1000 + now.tv_usec / 1000) - philo[j].start), j);
				pthread_mutex_unlock(philo[j].print);
				pthread_mutex_unlock(philo[j].is_alive_mutex);
				return (NULL);
			}
			if (!ft_mutex_int(&philo[j].win, philo[j].win_mutex))
				return (NULL);
			j++;
		}
	}
	return (NULL);
}

//void	initialize_philo()

int	main(int argc, char **argv)
{
	int				n_philo;
	int				die;
	int				eat;
	int				sleep;
	int				win;
	int				i;
	int				life;
	unsigned long	start;
	struct timeval	starttmp;
	pthread_t		*philo_thread;
	pthread_t		controller;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*last_meal;
	pthread_mutex_t	print;
	pthread_mutex_t	is_alive;
	pthread_mutex_t	win_mutex;
	t_philosopher	*philo;

	if (argc == 6 || argc == 5)
	{
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0 || (argc == 6 && ft_atoi(argv[5]) <= 0))
			return (1);
		philo_thread = ft_calloc(sizeof(pthread_t), ft_atoi(argv[1]) + 1);
		forks = ft_calloc(sizeof(pthread_mutex_t), ft_atoi(argv[1]) + 1);
		last_meal = ft_calloc(sizeof(pthread_mutex_t), ft_atoi(argv[1]) + 1);
		philo = ft_calloc(sizeof(t_philosopher), ft_atoi(argv[1]) + 1);
		n_philo = atoi(argv[1]);
		die = atoi(argv[2]);
		eat = atoi(argv[3]);
		sleep = atoi(argv[4]);
		if (argc == 6)
		{
			win = atoi(argv[5]);
			if (win <= 0)
				return 1;
		}
		else
			win = -1;
		i = 0;
		while (i < n_philo)
		{
			pthread_mutex_init(&forks[i], NULL);
			pthread_mutex_init(&last_meal[i], NULL);
			i++;
		}
		pthread_mutex_init(&print, NULL);
		pthread_mutex_init(&is_alive, NULL);
		pthread_mutex_init(&win_mutex, NULL);
		i = 0;
		life = 1;
		gettimeofday(&starttmp, NULL);
		start = starttmp.tv_sec * 1000 + starttmp.tv_usec / 1000;
		while (i < n_philo)
		{
			philo[i].id = i;
			philo[i].eat = eat;
			philo[i].sleep = sleep;
			philo[i].die = die;
			philo[i].is_alive = &life;
			philo[i].forks = forks;
			philo[i].num = n_philo;
			philo[i].win = win;
			philo[i].print = &print;
			philo[i].last_meal_mutex = &last_meal[i];
			philo[i].is_alive_mutex = &is_alive;
			philo[i].last_meal = 0;
			philo[i].start = start;
			philo[i].win_mutex = &win_mutex;
			pthread_create(&(philo_thread[i]), NULL, single_philo, &philo[i]);
			i++;
		}
		pthread_create(&controller, NULL, controller_func, philo);
		i = 0;
		pthread_join(controller, NULL);
		while (i < n_philo)
		{
			pthread_join(philo_thread[i], NULL);
			i++;
		}
		return (0);
	}
}
