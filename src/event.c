/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 10:08:56 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 14:43:12 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <fractol.h>

#define TRANS 5

void	event_color(int keycode, t_mlx *mlx)
{
	if (keycode == 18)
		mlx->color = g_rainbow;
	if (keycode == 19)
		mlx->color = g_pink;
	if (keycode == 20)
		mlx->color = g_rand1;
	if (keycode == 21)
		mlx->color = g_rand2;
	if (keycode == 23)
		mlx->color = g_pink;
	if (keycode == 22)
		mlx->color = g_pink;
	if (keycode == 26)
		mlx->color = g_pink;
	if (keycode == 28)
		mlx->color = g_pink;
	if (keycode == 25)
		mlx->color = g_pink;
}

void	event_move(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->origin->y -= TRANS * mlx->zoom;
	if (keycode == 1)
		mlx->origin->y += TRANS * mlx->zoom;
	if (keycode == 0)
		mlx->origin->x += TRANS * mlx->zoom;
	if (keycode == 2)
		mlx->origin->x -= TRANS * mlx->zoom;
}

int		event_key(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->mlx, ((t_mlx *)param)->win);
		exit(0);
	}
	if (keycode == 115)
	{
		mlx->zoom = .005;
		mlx->origin->x = -2;
		mlx->origin->y = -2;
	}
	event_color(keycode, mlx);
	event_move(keycode, mlx);
	redraw(mlx);
	return (0);
}

int		event_close(void)
{
	exit(0);
}
