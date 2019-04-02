/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 10:08:56 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 13:11:26 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <fractol.h>

#define TRANS 5

int		event_key(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->mlx, ((t_mlx *)param)->win);
		exit(0);
	}
	if (keycode == 13)
		mlx->origin->y -= TRANS * mlx->zoom;
	if (keycode == 1)
		mlx->origin->y += TRANS * mlx->zoom;
	if (keycode == 0)
		mlx->origin->x += TRANS * mlx->zoom;
	if (keycode == 2)
		mlx->origin->x -= TRANS * mlx->zoom;
	if (keycode == 115)
	{
		mlx->zoom = .005;
		mlx->origin->x = -2;
		mlx->origin->y = -2;
	}
	redraw(mlx);
	return (0);
}

int		event_close(void)
{
	exit(0);
}
