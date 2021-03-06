/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:43:47 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 14:51:31 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <fractol.h>

void	thread_join(pthread_t *threads, t_mlx *mlx)
{
	int i;
	int	*arg;

	i = 0;
	arg = malloc(sizeof(int));
	while (i < mlx->threads)
	{
		pthread_join(threads[i], (void **)arg);
		i++;
	}
	free(arg);
}

void	startup_threads(t_mlx *mlx)
{
	pthread_t	*threads;
	int			i;
	t_args		*args;

	i = 0;
	threads = malloc(sizeof(pthread_t) * mlx->threads);
	while (i < mlx->threads)
	{
		args = malloc(sizeof(t_args));
		args->mlx = mlx;
		args->start = i;
		pthread_create(&threads[i], NULL, mlx->f, args);
		i++;
	}
	thread_join(threads, mlx);
	free(threads);
}
