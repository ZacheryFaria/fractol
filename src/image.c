/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 11:58:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/01 17:21:05 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include <fractol.h>
#include <stdio.h>

t_image	*image_new(t_mlx *mlx)
{
	t_image *ret;

	if (!(ret = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(ret->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height)))
	{
		free(ret);
		return (NULL);
	}
	ret->ptr = (int *)mlx_get_data_addr(ret->img, &ret->bpp,
		&ret->wid, &ret->end);
	return (ret);
}

void	image_set_pixel(t_mlx *mlx, t_coor *vec, int color)
{
	if (vec->y + 1 >= mlx->height)
		return ;
	if (!(vec->x < 0 || vec->x >= mlx->width)
		&& !(vec->y < 0 || vec->y >= mlx->height))
		mlx->img->ptr[(int)(vec->x + (vec->y * mlx->img->wid / 4))] = color;
}

double	percent(double start, double end, double current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_color(t_coor start, t_coor end, t_coor current, t_coor delta)
{
	double	p;
	int		red;
	int		green;
	int		blue;

	if (delta.x > delta.y)
		p = percent(start.x, end.x, current.x);
	else
		p = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, p);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, p);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, p);
	return ((red << 16) | (green << 8) | blue);
}
