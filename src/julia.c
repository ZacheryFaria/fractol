/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:14 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 14:19:26 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <colors.h>

static int	calc_pixel(t_coor *coord, t_coor c, int max_itr)
{
	int		itr;
	double	zx;
	double	zy;
	double	temp;

	itr = 0;
	zx = coord->x;
	zy = coord->y;
	while (itr < max_itr && zx * zx + zy * zy < 4)
	{
		temp = zx * zx - zy * zy;
		zy = 2 * zx * zy + c.y;
		zx = temp + c.x;
		itr++;
	}
	return (itr);
}

void		*julia_run(void *ta)
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
			res = calc_pixel(&p, *args->mlx->c, args->mlx->max_itr);
			if (res == args->mlx->max_itr)
				image_set_pixel(args->mlx, &(t_coor){x, y, 0}, BLACK);
			else
				image_set_pixel(args->mlx, &(t_coor){x, y, 0},
					get_color(res, g_rainbow, args->mlx));
		}
		y += args->mlx->threads;
	}
	free(ta);
	return (0);
}
