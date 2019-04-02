/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:09:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 13:10:20 by zfaria           ###   ########.fr       */
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
	t_mlx	*mlx;
	
	args = ta;
	mlx = args->mlx;
	y = args->start;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			t_coor p;
			p.x = x * mlx->zoom + mlx->origin->x;
			p.y = y * mlx->zoom + mlx->origin->y;
			int res = calc_pixel(&p, 0, mlx->max_itr);
			if (res == mlx->max_itr)
				image_set_pixel(mlx, &(t_coor){x, y, 0}, BLACK);
			else
			{
				double s = scale(res, (t_coor){0.0, 1.0, 0}, (t_coor){0, mlx->max_itr, 0});
				if (s > 0.8)
				{
					int color = get_color((t_coor){1.0, 0, RED}, (t_coor){.8, 0, ORANGE}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.6)
				{
					int color = get_color((t_coor){0.8, 0, ORANGE}, (t_coor){.6, 0, YELLOW}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.4)
				{
					int color = get_color((t_coor){.6, 0, YELLOW}, (t_coor){.4, 0, GREEN}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.2)
				{
					int color = get_color((t_coor){.4, 0, GREEN}, (t_coor){.2, 0, BLUE}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.1)
				{
					int color = get_color((t_coor){.2, 0, BLUE}, (t_coor){.1, 0, PURPLE}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.25)
				{
					int color = get_color((t_coor){.1, 0, PURPLE}, (t_coor){.25, 0, GRAY}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else
				{
					image_set_pixel(mlx, &(t_coor){x, y, 0}, GRAY);
				}
				
			}
			x++;
		}
		y += mlx->threads;
	}
	free(ta);
	return (0);
}
