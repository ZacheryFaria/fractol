/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:29:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/01 15:39:15 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include <fractol.h>
#include "colors.h"

void	process_args(int argc, char **argv, t_mlx *mlx)
{
	(void)argv;
	if (argc < 2)
	{
		ft_putendl("usage: ./fractol <fractal>");
		exit(0);
	}
	if (argc == 3)
	{
		mlx->threads = ft_atoi(argv[2]);
	}
	else
	{
		mlx->threads = 2;
	}
}

void	bind_event(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 17, event_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, event_close, mlx);
	mlx_hook(mlx->win, 6, 1L << 17, event_mouse, mlx);
	mlx_hook(mlx->win, 4, 1L << 17, event_mouse_pressed, mlx);
	mlx_hook(mlx->win, 5, 1L << 17, event_mouse_released, mlx);
	mlx_loop_hook(mlx->mlx, fdf_loop, mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	process_args(argc, argv, mlx);
	mlx->origin = &(t_coor){0, 0, 0};
	mlx->zoom = 1;
	mlx->height = 1080;
	mlx->width = 1920;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "fractol");
	mlx->img = image_new(mlx);
	bind_event(mlx);
	julia_run(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
