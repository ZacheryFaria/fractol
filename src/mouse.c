/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:17:23 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/01 13:54:30 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

int	event_mouse(int x, int y, void *ptr)
{
	t_mlx *mlx;
	(void)x;
	(void)y;

	mlx = ptr;
	return (0);
}

int	event_mouse_pressed(int keycode, int x, int y, void *ptr)
{
	t_mlx *mlx;
	(void)x;
	(void)y;
	(void)keycode;
	mlx = ptr;
	return (0);
}

int	event_mouse_released(int keycode, int x, int y, void *ptr)
{
	t_mlx *mlx;
	(void)x;
	(void)y;
	(void)keycode;
	mlx = ptr;
	return (0);
}

int	fdf_loop(void *ptr)
{
	t_mlx *mlx;

	mlx = ptr;
	return (0);
}
