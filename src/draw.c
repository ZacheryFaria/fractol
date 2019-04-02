/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:54:13 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/01 17:36:41 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <math.h>
#include <colors.h>
#include <mlx.h>

void	plot_map(t_mlx *mlx)
{
	startup_threads(mlx);
}

void	redraw(t_mlx *mlx)
{
	ft_bzero(mlx->img->ptr, mlx->img->wid * mlx->height);
	startup_threads(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
