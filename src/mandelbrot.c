/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:09:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 14:28:26 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <colors.h>

static int	calc_pixel(t_coor *coord, int itr, int max_itr)
{
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	temp;

	x = 0;
	y = 0;
	x0 = coord->x;
	y0 = coord->y;
	while (itr < max_itr && x * x + y * y <= 4)
	{
		temp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = temp;
		itr++;
	}
	return (itr);
}

void		*mandelbrot_run(void *ta)
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
				image_set_pixel(args->mlx, &(t_coor){x, y, 0}, get_color(res,
					args->mlx));
		}
		y += args->mlx->threads;
	}
	free(ta);
	return (0);
}
