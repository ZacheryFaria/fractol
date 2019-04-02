/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:05:06 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 15:19:04 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <colors.h>
#include <math.h>

static int	calc_pixel(t_coor *coord, int itr, int max_itr)
{
	double	zx;
	double	zy;
	double	x;
	double	y;
	double	temp;

	x = coord->x;
	y = coord->y;
	zx = x;
	zy = y;
	while (itr < max_itr && zx * zx + zy * zy < 4)
	{
		temp = zx * zx - zy * zy + x;
		zy = fabs(2 * zx * zy) + y;
		zx = fabs(temp);
		itr++;
	}
	return (itr);
}

void		*burningship_run(void *ta)
{
	int		y;
	int		x;
	t_args	*args;
	t_coor	p;
	int		res;

	args = ta;
	y = args->start;
	while (y < args->mlx->height && (x = -1))
	{
		while (++x < args->mlx->width)
		{
			p.x = x * args->mlx->zoom + args->mlx->origin->x;
			p.y = y * args->mlx->zoom + args->mlx->origin->y;
			res = calc_pixel(&p, 0, args->mlx->max_itr);
			if (res == args->mlx->max_itr)
				image_set_pixel(args->mlx, &(t_coor){x, y, 0}, BLACK);
			else
				image_set_pixel(args->mlx, &(t_coor){x, y, 0},
					get_color(res, args->mlx));
		}
		y += args->mlx->threads;
	}
	free(ta);
	return (0);
}
