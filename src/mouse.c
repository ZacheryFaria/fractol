/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:17:23 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 13:06:59 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

int	julia_mouse_move(int x, int y, void *ptr)
{
	t_mlx	*mlx;

	mlx = ptr;
	mlx->c->x = (x) * 0.001;
	mlx->c->y = (y) * 0.001;
	redraw(mlx);
	return (0);
}

int	calc_zoom(int x, int y, double new_zoom, t_mlx *mlx)
{
	mlx->origin->y -= y * (new_zoom - mlx->zoom);
	mlx->origin->x -= x * (new_zoom - mlx->zoom);
	mlx->zoom = new_zoom;
	return (0);
}

int	event_mouse_pressed(int button, int x, int y, void *ptr)
{
	t_mlx *mlx;

	mlx = ptr;
	if (x <= mlx->width && x >= 0 && y >= 0 && y <= mlx->height)
	{
		if (button == 4)
			calc_zoom(x, y, mlx->zoom / 1.05, mlx);
		if (button == 5)
			calc_zoom(x, y, mlx->zoom * 1.05, mlx);
		mlx->update = 1;
	}
	return (0);
}

int	fdf_loop(void *ptr)
{
	t_mlx *mlx;

	mlx = ptr;
	if (mlx->update)
	{
		redraw(mlx);
		mlx->update = 0;
	}
	return (0);
}
