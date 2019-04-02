/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:29:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 14:59:45 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include <fractol.h>
#include "colors.h"

void	process_args(int argc, char **argv, t_mlx *mlx)
{
	int i;

	(void)argv;
	if (argc < 2)
		die("usage: ./fractol <fractal>");
	i = 0;
	while (++i < argc)
	{
		if (ft_strncmp("-thread=", argv[i], 8) == 0)
			mlx->threads = ft_atoi(argv[i] + 8);
		else if (ft_strncmp("-lod=", argv[i], 5) == 0)
			mlx->max_itr = ft_atoi(argv[i] + 5);
		else
		{
			if (ft_strcmp("julia", argv[i]) == 0)
				mlx->f = &julia_run;
			else if (ft_strcmp("mandelbrot", argv[i]) == 0)
				mlx->f = &mandelbrot_run;
		}
	}
	if (mlx->threads <= 0)
		mlx->threads = 8;
	if (mlx->max_itr <= 0)
		mlx->max_itr = 255;
}

void	bind_event(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 17, event_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, event_close, mlx);
	mlx_hook(mlx->win, 4, 1L << 17, event_mouse_pressed, mlx);
	mlx_loop_hook(mlx->mlx, fdf_loop, mlx);
	mlx_hook(mlx->win, 6, 0, julia_mouse_move, mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->max_itr = 255;
	process_args(argc, argv, mlx);
	if (mlx->f == 0)
		die("No fractal found");
	mlx->origin = &(t_coor){-2, -2, 0};
	mlx->zoom = .005;
	mlx->height = 800;
	mlx->color = g_rainbow;
	mlx->width = 800;
	mlx->c = new_coor(-.5, .5, 0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "fractol");
	mlx->img = image_new(mlx);
	bind_event(mlx);
	startup_threads(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
